using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Reflection;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Server.Kestrel.Https;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using System.Threading;
using Serilog;
using Serilog.Core;
using Serilog.Events;

namespace Oxitip {
    public class Program {
        public static int Main (string[] args) {

            var configuration = new ConfigurationBuilder()
            .SetBasePath(Directory.GetCurrentDirectory())
            .AddJsonFile("appsettings.json")
            .Build();


             Log.Logger = new LoggerConfiguration()
            .ReadFrom.Configuration(configuration)
            .CreateLogger();

        try
        {
            Log.Information("Starting web host");
            CreateHostBuilder(args).Build().Run();
            return 0;
        }
        catch (Exception ex)
        {
            Log.Fatal(ex, "Host terminated unexpectedly");
            return 1;
        }
        finally
        {
            Log.CloseAndFlush();
        }
         
        }

        public static IHostBuilder CreateHostBuilder (string[] args) =>
            Host.CreateDefaultBuilder (args)
            .UseContentRoot (Path.GetDirectoryName (Assembly.GetEntryAssembly ().Location))
            .UseSerilog()
            .ConfigureWebHostDefaults (webBuilder => {
                webBuilder.UseStartup<Startup> ();//.UseUrls(urls: new String[] { "http://localhost:5000;" }); //http://oxitip.com:80;http://wwww.oxitip.com:80;https://oxitip:443;

                webBuilder.PreferHostingUrls (false);
                 webBuilder.UseKestrel (k => {
                    var appServices = k.ApplicationServices;

                    k.Listen(IPAddress.Any, 80);


                 });
                
            });
    }
}