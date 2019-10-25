using STAGIOPTR.Database;
using STAGIOPTR.Models;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class SignupViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        public Command AddPatientUserCommand { get; }

        private User _user;

        public User User
        {
            get { return _user; }
            set { SetProperty(ref _user, value); }
        }

        public SignupViewModel()
        {
            User = new User();
            AddPatientUserCommand = new Command(ExecuteAddPatientUserCommand);
        }

        private async void ExecuteAddPatientUserCommand()
        {
            this.User.AccessLevel = 4;
            await PushAsync<UserPatientViewModel>(this.User);
        }

    }
}
