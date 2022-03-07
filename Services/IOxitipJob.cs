using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Hangfire;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.SignalR;
using Microsoft.Extensions.Logging;
using Oxitip.Services;

namespace Oxitip.Services {
    public interface IOxitipJob {
        Task<string> ExecuteMultilineTask (string Expression, string Identity, string Email, string TaskIdentity, bool IsQueueTask);
        Task<string> ExecuteSinglelineTask (string Expression, string Identity, string Email, string TaskIdentity, bool IsQueueTask);

        Task<string> GetMultilineVariableLength (string Expression);
        Task<string> GetSinglelineVariableLength (string Expression);

    }

    public class OxitipJob : IOxitipJob {
        private readonly ILogger<IOxitipJob> _logger;
        private readonly IEmailSender _emailSender;
        private readonly EmailConfiguration _emailConfig;
        private IHostingEnvironment _hostingEnvironment;
        private readonly IHubContext<OxitipHub> _oxitipHubHubContext;

        public OxitipJob (ILogger<IOxitipJob> logger, IHostingEnvironment env, IEmailSender emailSender, EmailConfiguration emailConfig, IHubContext<OxitipHub> oxitipHubHubContext) {
            _hostingEnvironment = env;
            _logger = logger;
            _emailSender = emailSender;
            _emailConfig = emailConfig;
            _oxitipHubHubContext = oxitipHubHubContext;
        }

        public async Task<string> ExecuteMultilineTask (string Expression, string Identity, string Email, string TaskIdentity, bool IsQueueTask) {
            var timer = new Stopwatch ();
            timer.Start ();

            string expression = "";
            var textLines = Expression.Split ('\n');
            foreach (var line in textLines) {
                if (line.Trim ().Length > 1) { expression = expression + '"' + line.Trim () + '"' + ' '; }
            }

            var output = this.RunCommand (expression, "Citip"); //"The information theoretic expression is TRUE."; //

            timer.Stop ();
            if (OxitipTaskDB.OxitipTasks.ContainsKey (TaskIdentity)) {
                var oxitipTask = OxitipTaskDB.OxitipTasks[TaskIdentity];
                if (oxitipTask != null) {
                    oxitipTask.Result = output;
                    oxitipTask.TimeTaken = timer.ElapsedMilliseconds + "ms";
                }
            }
            if (IsQueueTask) {
                try {

                    await _oxitipHubHubContext.Clients.Group (TaskIdentity).SendAsync ("TaskComplete", TaskIdentity, output);

                } catch (Exception ex) {

                    _logger.LogError ("SignalR TaskComplete Error");
                    _logger.LogError (ex.Message);
                }

                try {
                    if (_emailConfig.SendOnResult && !string.IsNullOrWhiteSpace (_emailConfig.SendTo)) {
                        var message = new Message (new string[] { _emailConfig.SendTo }, "oXitip Task Result - " + TaskIdentity, "Multiline \n\n " + expression + " \n\n Time Taken " + timer.ElapsedMilliseconds + "ms \n\n " + output + " \n\n " + Email);
                        _emailSender.SendEmail (message);
                    }
                } catch (Exception ex) {

                    _logger.LogError ("SendOnResponse Error");
                    _logger.LogError (ex.Message);
                }
                try {
                    if (!string.IsNullOrWhiteSpace(Email)) {
                        var message = new Message (new string[] { Email }, "oXitip Result", expression + " \n\n " + output);
                        _emailSender.SendEmail (message);
                    }
                } catch (Exception ex) {

                    _logger.LogError ("SendOnRequest Error");
                    _logger.LogError (ex.Message);
                }
            }
            if (timer.ElapsedMilliseconds > 2000) {
                _logger.LogWarning ("Multiline {0} - Time Taken {1}ms - {2} - {3}", expression, timer.ElapsedMilliseconds, TaskIdentity, Identity);
                _logger.LogWarning (output);
            } else {
                _logger.LogInformation ("Multiline {0} - Time Taken {1}ms - {2} - {3}", expression, timer.ElapsedMilliseconds, TaskIdentity, Identity);
                _logger.LogInformation (output);
            }
            return output;
        }
        public async Task<string> ExecuteSinglelineTask (string Expression, string Identity, string Email, string TaskIdentity, bool IsQueueTask) {
            var timer = new Stopwatch ();
            timer.Start ();

            string expression = Expression.Replace ("'", "\"");

            var output = this.RunCommand (expression, "Citip"); //"The information theoretic expression is TRUE."; //

            timer.Stop ();
            if (OxitipTaskDB.OxitipTasks.ContainsKey (TaskIdentity)) {
                var oxitipTask = OxitipTaskDB.OxitipTasks[TaskIdentity];
                if (oxitipTask != null) {
                    oxitipTask.Result = output;
                    oxitipTask.TimeTaken = timer.ElapsedMilliseconds + "ms";
                }
            }

            if (IsQueueTask) {
                try {

                    await _oxitipHubHubContext.Clients.Group (TaskIdentity).SendAsync ("TaskComplete", TaskIdentity, output);

                } catch (Exception ex) {

                    _logger.LogError ("SignalR TaskComplete Error");
                    _logger.LogError (ex.Message);
                }

                try {
                    if (_emailConfig.SendOnResult && !string.IsNullOrWhiteSpace (_emailConfig.SendTo)) {
                        var message = new Message (new string[] { _emailConfig.SendTo }, "oXitip Task Result - " + TaskIdentity, "Multiline \n\n " + expression + " \n\n Time Taken " + timer.ElapsedMilliseconds + "ms \n\n " + output + " \n\n " + Email);
                        _emailSender.SendEmail (message);
                    }
                } catch (Exception ex) {

                    _logger.LogError ("SendOnResponse Error");
                    _logger.LogError (ex.Message);
                }
                try {
                    if (!string.IsNullOrWhiteSpace (Email)) {
                        var message = new Message (new string[] { Email }, "oXitip Result", expression + " \n\n " + output);
                        _emailSender.SendEmail (message);
                    }
                } catch (Exception ex) {

                    _logger.LogError ("SendOnRequest Error");
                    _logger.LogError (ex.Message);
                }
            }

            if (timer.ElapsedMilliseconds > 2000) {
                _logger.LogWarning ("Singleline {0} - Time Taken {1}ms - {2} - {3}", expression, timer.ElapsedMilliseconds, TaskIdentity, Identity);
                _logger.LogWarning (output);
            } else {
                _logger.LogInformation ("Singleline {0} - Time Taken {1}ms - {2} - {3}", expression, timer.ElapsedMilliseconds, TaskIdentity, Identity);
                _logger.LogInformation (output);
            }

            return output;
        }

        public async Task<string> GetMultilineVariableLength (string Expression) {
            string expression = "";
            var textLines = Expression.Split ('\n');

            foreach (var line in textLines) {
                if (line.Trim ().Length > 1) { expression = expression + '"' + line.Trim () + '"' + ' '; }
            }

            return this.RunCommand (expression, "oXitipLen");

        }
        public async Task<string> GetSinglelineVariableLength (string Expression) {
            string expression = Expression.Replace ("'", "\"");
            return this.RunCommand (expression, "oXitipLen");
        }

        string RunCommand (string args, string binary) {

            string command;
            command = _hostingEnvironment.ContentRootPath;
            command = Path.Combine (command, "binaries");
            command = Path.Combine (command, binary);

            var process = new Process () {
                StartInfo = new ProcessStartInfo {
                FileName = command,
                Arguments = args,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true,
                }
            };
            process.Start ();
            string output = process.StandardOutput.ReadToEnd ();
            string error = process.StandardError.ReadToEnd ();
            process.WaitForExit ();

            if (string.IsNullOrEmpty (error)) { return output; } else { return error; }
        }
    }

}