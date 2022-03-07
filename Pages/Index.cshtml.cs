using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Hangfire;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.SignalR;
using Microsoft.Extensions.Logging;
using Oxitip.Services;
using Serilog;
using Serilog.Core;
using Serilog.Events;
using Microsoft.Extensions.Configuration;

namespace Oxitip.Pages {
    public class IndexModel : PageModel {
        private readonly ILogger<IndexModel> _logger;
        private readonly IEmailSender _emailSender;
        private readonly EmailConfiguration _emailConfig;
        private IHostingEnvironment _hostingEnvironment;
        private readonly IOxitipJob _oxitipJob;
        private readonly IHubContext<OxitipHub> _oxitipHubHubContext;
        
        private readonly IConfiguration _configuration;

        public string OutputSingle { get; set; }
        public string OutputMulti { get; set; }
        
        [BindProperty]
        public string Expression { get; set; } = "'I(X;Y|Z) <= I(X;Y)' 'X/Y/Z'";

        [BindProperty]
        public string ExpressionMultiline { get; set; } = "I(X;Y|Z) <= I(X;Y)\nX/Y/Z";

        public string projectRootFolder { get; set; }
        
        public int MinLengthFoQueue {get; set;} 

        public IndexModel (ILogger<IndexModel> logger, IHostingEnvironment env, IEmailSender emailSender, 
            EmailConfiguration emailConfig, IOxitipJob oxitipJob, IHubContext<OxitipHub> oxitipHubHubContext,
            IConfiguration configuration) {
            _hostingEnvironment = env;
            _logger = logger;
            _emailSender = emailSender;
            _emailConfig = emailConfig;
            _oxitipJob = oxitipJob;
            _oxitipHubHubContext = oxitipHubHubContext;
            _configuration = configuration;

            
             if(int.TryParse(_configuration["oXitip:MinLengthFoQueue"],out int length)){
                this.MinLengthFoQueue = length;
             }
        }

        public void OnGet () {
            this.projectRootFolder = _hostingEnvironment.ContentRootPath;
        }

      
        public async Task<JsonResult> OnPostSingle (string Expression, string Identity,string Email, string TaskIdentity) {
            if (!string.IsNullOrWhiteSpace (Expression)) {
                Expression = Expression.Replace ("'", "\"");
               
                var lengthResult = await _oxitipJob.GetSinglelineVariableLength(Expression);
                if(int.TryParse(lengthResult,out int length)){
                    if(length<MinLengthFoQueue){
                        var result = await _oxitipJob.ExecuteSinglelineTask(Expression,Identity,Email,TaskIdentity, false);
                         return new JsonResult(result);
                    }
                } else {
                    return new JsonResult(lengthResult);
                }
                
                try
                {
                    if (_emailConfig.SendOnRequest && !string.IsNullOrWhiteSpace(_emailConfig.SendTo))
                    {
                        var message = new Message(new string[] { _emailConfig.SendTo }, "New Oxitip Task - " + TaskIdentity, Expression + "  \n\n " + Email);
                        _emailSender.SendEmail(message);
                    }
                }
                catch (Exception ex)
                {
                    _logger.LogError("SendOnRequest Error");
                    _logger.LogError(ex.Message);
                }

                OxitipTaskDB.OxitipTasks.AddOrUpdate(TaskIdentity, new OxitipTask() { Expression = Expression, TaskIdentity = TaskIdentity, Identity = Identity, Email = Email },(TaskIdentity,oldTask)=> { return oldTask; });

                BackgroundJob.Enqueue<OxitipJob>(x => x.ExecuteSinglelineTask(Expression, Identity, Email, TaskIdentity, true));

                return new JsonResult("");
            }
            else {
                return new JsonResult("");
            }
        }

        public async Task<JsonResult> OnPostMulti (string ExpressionMultiline, string Identity,string Email, string TaskIdentity) {
            if (!string.IsNullOrWhiteSpace (ExpressionMultiline)) {

                var lengthResult = await _oxitipJob.GetMultilineVariableLength(ExpressionMultiline);
                if(int.TryParse(lengthResult,out int length)){
                    if(length<MinLengthFoQueue){
                        var result = await _oxitipJob.ExecuteMultilineTask(ExpressionMultiline,Identity,Email,TaskIdentity, false);
                         return new JsonResult(result);
                    }
                } else {
                    return new JsonResult(lengthResult);
                }
                
                try
                {
                    if (_emailConfig.SendOnRequest && !string.IsNullOrWhiteSpace(_emailConfig.SendTo))
                    {
                        var message = new Message(new string[] { _emailConfig.SendTo }, "New Oxitip Task - " + TaskIdentity, ExpressionMultiline + "  \n\n " + Email);
                        _emailSender.SendEmail(message);
                    }
                }
                catch (Exception ex)
                {
                    _logger.LogError("SendOnRequest Error");
                    _logger.LogError(ex.Message);
                }

                OxitipTaskDB.OxitipTasks.AddOrUpdate(TaskIdentity, new OxitipTask() { Expression = ExpressionMultiline, TaskIdentity = TaskIdentity, Identity = Identity, Email = Email },(TaskIdentity,oldTask)=> { return oldTask; });

                BackgroundJob.Enqueue<OxitipJob>(x => x.ExecuteMultilineTask(ExpressionMultiline, Identity, Email, TaskIdentity, true));

                return new JsonResult("");
            }
            else {
                return new JsonResult("");
            }
        }

        public JsonResult OnPostResult(string TaskIdentity)
        {
            if (!string.IsNullOrWhiteSpace(TaskIdentity))
            {
               

                var oxitipTask = OxitipTaskDB.OxitipTasks[TaskIdentity];

                return new JsonResult(oxitipTask);

            }
            else
            {
                return new JsonResult("");

            }
        }


    }
}