using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Collections.Concurrent;

namespace Oxitip.Services
{
    public static class OxitipTaskDB
    {
       public static readonly ConcurrentDictionary<string, OxitipTask> OxitipTasks = new ConcurrentDictionary<string, OxitipTask>(StringComparer.OrdinalIgnoreCase);
    }

    public class OxitipTask {
        public string Expression { get; set; }
        public string Identity { get; set; }
        public string TaskIdentity { get; set; }
        public string Result { get; set; }
        public string Email { get; set; }
        public string TimeTaken { get; set; }
    }
}
