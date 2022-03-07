using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.HttpsPolicy;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.AspNetCore.HttpOverrides;
using System.IO;
using Microsoft.Extensions.Logging;
using Microsoft.AspNetCore.SignalR;
using Oxitip.Services;
using Hangfire;
using Hangfire.MemoryStorage;
using HangfireBasicAuthenticationFilter;

namespace Oxitip
{
    public class Startup
    {
        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public IConfiguration Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
             /* var serviceProvider = services.BuildServiceProvider();
            var logger = serviceProvider.GetService<ILogger<Program>>();
            services.AddSingleton(typeof(ILogger), logger);*/
           // services.AddLogging();
            /*services.AddHsts(options =>
            {
                options.Preload = true;
                options.IncludeSubDomains = true;
                options.MaxAge = TimeSpan.FromDays(60);
                options.ExcludedHosts.Add("oxitip.com");
                options.ExcludedHosts.Add("www.oxitip.com");
            });*/
       var emailConfig = Configuration
        .GetSection("EmailConfiguration")
        .Get<EmailConfiguration>();
    services.AddSingleton(emailConfig);
            services.AddSingleton<IEmailSender, EmailSender>();
            services.AddSingleton<IOxitipJob, OxitipJob>();
            

            services.AddSignalR();

            services.AddRazorPages();

            // Add This
            services.AddHangfire(config =>
            {
                config.UseMemoryStorage();
            });

            //services.AddHangfireServer();

        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            else
            {
                app.UseExceptionHandler("/Error");
                // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
                app.UseHsts();
                

                /*app.UseForwardedHeaders(new ForwardedHeadersOptions
                {
                    ForwardedHeaders = ForwardedHeaders.XForwardedFor | ForwardedHeaders.XForwardedProto
                });*/
            }

            //app.UseHttpsRedirection();
            app.UseStaticFiles();

            app.UseRouting();

            app.UseAuthorization();

            // Add This
            var workerThreads = int.Parse(Configuration["Hangfire:WorkerThreads"]);// .GetSection("EmailConfiguration").Get<EmailConfiguration>();
            app.UseHangfireDashboard("/jobs",new DashboardOptions
        {
            //AppPath = "" //The path for the Back To Site link. Set to null in order to hide the Back To  Site link.
            DashboardTitle = "oXitip",
            Authorization = new[]
        {
                new HangfireCustomBasicAuthenticationFilter{
                    User = Configuration["Hangfire:UserName"],
                    Pass = Configuration["Hangfire:Password"]
                }
            }
        });
            var options = new BackgroundJobServerOptions { WorkerCount = workerThreads };
            app.UseHangfireServer(options);

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapRazorPages();
                endpoints.MapHub<OxitipHub>("/oxitipHub");

            });
        }
    }
}
