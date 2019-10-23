using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;
using System.Diagnostics;

namespace STAGIOPTR.ViewModels
{
    public class LoginViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        public Command LoginCommand { get; }

        public Command SignupCommand { get; }

        private User _user;

        public User User
        {
            get { return _user; }
            set { SetProperty(ref _user, value); }
        }

        private string _email;

        public string Email
        {
            get { return _email; }
            set { SetProperty(ref _email, value); }
        }

        private string _password;

        public string Password
        {
            get { return _password; }
            set { SetProperty(ref _password, value); }
        }

        public LoginViewModel()
        {
            this.User = new User();
            LoginCommand = new Command(ExecuteLoginCommand);
            SignupCommand = new Command(ExecuteSignupCommand);
            User User = database.getUserPerLogin("admin@admin", "admin");
            Debug.WriteLine(User);
            if (User == null)
            {
                User Admin = new User
                {
                    Name = "Administrador",
                    CPF = "007",
                    Email = "admin@admin",
                    Password = "admin",
                    AccessLevel = 1,
                    IdPatient = 0
                };
                database.InsertUsers(Admin);
            }
        }

        public void ExecuteLoginCommand()
        {
            Debug.WriteLine("user: "+ this.Email);
            Debug.WriteLine("password: "+ this.Password);
            User User = database.getUserPerLogin(this.Email, this.Password);
            if (User.AccessLevel == 1)
                LoginAsync<MainViewModel>();
            else
                LoginAsync<PatientViewModel>(User);
        }

        private async void ExecuteSignupCommand()
        {
            await PushAsync<SignupViewModel>();
        }
    }
}
