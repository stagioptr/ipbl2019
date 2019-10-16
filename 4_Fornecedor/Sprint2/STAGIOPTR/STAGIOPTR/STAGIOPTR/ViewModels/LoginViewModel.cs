using STAGIOPTR.Models;
using STAGIOPTR.Database;
using Xamarin.Forms;
using System.Diagnostics;

namespace STAGIOPTR.ViewModels
{
    public class LoginViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        public Command LoginUserCommand { get; }

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
            LoginUserCommand = new Command(ExecuteLoginUserCommand);
            User User = database.getUserPerLogin("admin@admin", "admin");
            Debug.WriteLine(User == null);
            if (User == null)
            {
                User Admin = new User
                {
                    Name = "Administrador",
                    CPF = 007,
                    Email = "admin@admin",
                    Password = "admin",
                    AccessLevel = 1
                };
                database.InsertUsers(Admin);
            }
            
        }

        public void ExecuteLoginUserCommand()
        {
            Debug.WriteLine("user: "+ this.Email);
            Debug.WriteLine("password: "+ this.Password);
        }
    }
}
