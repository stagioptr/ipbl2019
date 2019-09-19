using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using Xamarin.Forms;


namespace STAGIOPTR.ViewModels
{
    public class SOSButtonViewModel : BaseViewModel
    {
        public Command SOSButtonCommand { get; }

        public SOSButtonViewModel()
        {
            SOSButtonCommand = new Command(ExecuteSOSButtonCommand);
        }
        private async void ExecuteSOSButtonCommand()
        {
            await PushAsync<SOSButtonViewModel>();
        }
    }
}