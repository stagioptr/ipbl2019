using STAGIOPTR.Views;
using System.Diagnostics;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    class MainViewModel : BaseViewModel
    {
        public Command LogoutCommand { get; set; }

        public MainViewModel()
        {
            LogoutCommand = new Command(this.Logout);
        }
    }
}
