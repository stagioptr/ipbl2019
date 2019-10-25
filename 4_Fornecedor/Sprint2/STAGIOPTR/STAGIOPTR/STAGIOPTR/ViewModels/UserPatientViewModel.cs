using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class UserPatientViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        public Command LoadPatientsCommand { get; }

        public Command SignUpCommand { get; }

        private ObservableCollection<Patient> _patients;

        public ObservableCollection<Patient> Patients
        {
            get { return _patients; }
            set { SetProperty(ref _patients, value); }
        }

        private User _user;

        public User User
        {
            get { return _user; }
            set { SetProperty(ref _user, value); }
        }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        private Patient _patientSelected;

        public Patient PatientSelected
        {
            get { return _patientSelected; }
            set { _patientSelected = value; }
        }



        public UserPatientViewModel(User User)
        {
            this.User = User;
            _patients = new ObservableCollection<Patient>();
            this.IsLoading = true;
            _ = this.LoadAsync();
            LoadPatientsCommand = new Command(LoadAsyncList);
            SignUpCommand = new Command(ExecuteSignUpCommand);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }
        public override async Task LoadAsync()
        {
            var patients = await database.ListPatients();
            this.Patients.Clear();
            foreach (var patient in patients)
            {
                this.Patients.Add(patient);
            }
            this.IsLoading = false;
        }

        public void ExecuteSignUpCommand()
        {
            this.User.IdPatient = this.PatientSelected.Id;
            this.User.Patient = this.PatientSelected;
            Debug.WriteLine("Name: " + this.User.Name);
            Debug.WriteLine("CPF: " + this.User.CPF);
            Debug.WriteLine("Email: " + this.User.Email);
            Debug.WriteLine("Password: " + this.User.Password);
            Debug.WriteLine("AccessLevel: " + this.User.AccessLevel);
            Debug.WriteLine("idPatient: " + this.User.IdPatient);
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
