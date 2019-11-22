using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientsListViewModel : BaseViewModel
    {
        private ObservableCollection<Patient> _patients;
        DatabaseConnection database = new DatabaseConnection();

        public Command AddPatientCommand { get; }

        public Command LoadPatientsCommand { get; }

        public Command<Patient> ShowPatientCommand { get; }

        public ObservableCollection<Patient> Patients
        {
            get { return _patients; }
            set { SetProperty(ref _patients, value); }
        }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }


        public PatientsListViewModel()
        {
            Patients = new ObservableCollection<Patient>();
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddPatientCommand = new Command(ExecuteAddPatientCommand);
            ShowPatientCommand = new Command<Patient>(ExecuteShowPatientCommand);
            LoadPatientsCommand = new Command(LoadAsyncList);
        }

        private async void ExecuteShowPatientCommand(Patient patient)
        {
            await PushAsync<PatientViewModel>(patient);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var patients = database.ListPatients();
            this.Patients.Clear();
            foreach (var patient in patients)
            {
                this.Patients.Add(patient);
            }
            this.IsLoading = false;
        }

        private async void ExecuteAddPatientCommand()
        {
            await PushAsync<PatientAddViewModel>();
        }

        private async void ExecuteAlterPatientCommand(Patient Patient)
        {
            await PushAsync<PatientViewModel>(Patient);
        }
    }
}
