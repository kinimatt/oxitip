using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.SignalR;
using System.Threading.Tasks;

namespace Oxitip.Services
{
   
        public class OxitipHub : Hub
        {
            public async Task SendMessage(string user, string message)
            {
                await Clients.All.SendAsync("ReceiveMessage", user, message);
            }
       
        public async Task AddToGroup(string TaskIdentity)
            {
                await Groups.AddToGroupAsync(Context.ConnectionId, TaskIdentity);

                await Clients.Group(TaskIdentity).SendAsync("Send", $"{Context.ConnectionId} has joined the group {TaskIdentity}.");
            }

            public async Task RemoveFromGroup(string TaskIdentity)
            {
                await Groups.RemoveFromGroupAsync(Context.ConnectionId, TaskIdentity);

                await Clients.Group(TaskIdentity).SendAsync("Send", $"{Context.ConnectionId} has left the group {TaskIdentity}.");
            }
    }
}
