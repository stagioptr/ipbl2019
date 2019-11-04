using STAGIOPTR.Database;
using STAGIOPTR.Views;
using System.Diagnostics;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    class MainViewModel : BaseViewModel
    {
        DatabaseConnection _database = new DatabaseConnection();
        public Command LogoutCommand { get; set; }

        public MainViewModel()
        {
            LogoutCommand = new Command(this.Logout);
        }
    }
}
