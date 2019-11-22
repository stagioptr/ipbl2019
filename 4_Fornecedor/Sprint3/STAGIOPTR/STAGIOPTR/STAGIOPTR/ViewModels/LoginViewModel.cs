using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;
using System.Diagnostics;
using STAGIOPTR.Helpers;

namespace STAGIOPTR.ViewModels
{
    public class LoginViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        MongoDatabase mongoDatabase = new MongoDatabase();

        public Command LoginCommand { get; }

        public Command SignupCommand { get; }

        private User _user;

        public User User
        {
            get { return _user; }
            set { SetProperty(ref _user, value); }
        }

        private string _errors;

        public string Errors
        {
            get { return _errors; }
            set { SetProperty(ref _errors, value); }
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
            //this.mongoDatabase.GetSensor();
            this.User = new User();
            LoginCommand = new Command(ExecuteLoginCommand);
            SignupCommand = new Command(ExecuteSignupCommand);
            User User = database.GetUserPerLogin("cuidador@cuidador", "cuidador");
            Debug.WriteLine(User);
            if (User == null)
            {
                User Admin = new User
                {
                    Name = "Cuidador",
                    CPF = "007",
                    Email = "cuidador@cuidador",
                    Password = "cuidador",
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
            User User = this.ValidationRules();
            if (User != null)
            {
                switch (User.AccessLevel)
                {
                    case 1:
                        LoginAsync<MainViewModel>();
                        break;
                    case 3:
                        LoginAsync<TabbedPatientViewModel>();
                        break;
                    case 4:
                        LoginAsync<PatientViewModel>(User);
                        break;
                }
            }
        }

        private async void ExecuteSignupCommand()
        {
            await PushAsync<SignupViewModel>();
        }


        private User ValidationRules()
        {
            User User = database.GetUserPerLogin(this.Email, this.Password);
            if (User == null)
            {
                this.Errors = "E-mail ou senha inválidos!";
                return null;
            }
            database.InsertLoggedUser(new UserLogged{
                IdUser = User.Id,
                User = User
            });;
            return User;
        }
    }
}
