using STAGIOPTR.Database;
using STAGIOPTR.Models;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class SignupViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        
        public Command SignUpCommand { get; }

        private User _user;

        public User User
        {
            get { return _user; }
            set { SetProperty(ref _user, value); }
        }

        private string _cpfPatient;

        public string CPFPatient
        {
            get { return _cpfPatient; }
            set { SetProperty(ref _cpfPatient, value); }
        }


        public SignupViewModel()
        {
            User = new User();
            SignUpCommand = new Command(ExecuteSignUpCommand);
        }

        public void ExecuteSignUpCommand()
        {
            Patient Patient = database.GetPatientPerCPF(this.CPFPatient);
            this.User.IdPatient = Patient.Id;
            this.User.Patient = Patient;
            this.User.AccessLevel = 4;
            database.InsertUsers(this.User);
            this.Login();
        }

        public void Login()
        {
            database.InsertLoggedUser(new UserLogged
            {
                IdUser = this.User.Id,
                User = this.User
            });
            LoginAsync<PatientViewModel>(this.User);
        }

    }
}
