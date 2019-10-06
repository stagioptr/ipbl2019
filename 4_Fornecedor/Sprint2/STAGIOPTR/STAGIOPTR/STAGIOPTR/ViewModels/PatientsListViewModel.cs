using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using STAGIOPTR.Database;
using Xamarin.Forms;
using System.Threading.Tasks;
using System.Diagnostics;

namespace STAGIOPTR.ViewModels
{
    public class PatientsListViewModel : BaseViewModel
    {
        private ObservableCollection<Patient> _patients;
        DatabaseConnection database = new DatabaseConnection();

        public Command AddPatientCommand { get; }

        public Command<Patient> ShowPatientCommand { get; }

        public ObservableCollection<Patient> Patients
        {
            get { return _patients; }
            set { SetProperty(ref _patients, value); }
        }

        public PatientsListViewModel()
        {
            _patients = new ObservableCollection<Patient>();
            this.LoadAsync();
            AddPatientCommand = new Command(ExecuteAddPatientCommand);
            ShowPatientCommand = new Command<Patient>(ExecuteShowPatientCommand);
        }

        private async void ExecuteShowPatientCommand(Patient patient)
        {
            await PushAsync<PatientViewModel>(patient);
        }

        public override async Task LoadAsync()
        {
            var patients = await database.ListPatients();
            this.Patients.Clear();
            foreach (var patient in patients)
            {
                this.Patients.Add(patient);
            }
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
