using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using STAGIOPTR.Database;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientsListViewModel : BaseViewModel
    {
        private ObservableCollection<Patient> _patients;
        DatabaseConnection database = new DatabaseConnection();

        public Command AddPatientCommand { get; }

        public ObservableCollection<Patient> Patients
        {
            get { return _patients; }
            set { SetProperty(ref _patients, value); }
        }

        public PatientsListViewModel()
        {
            _patients = new ObservableCollection<Patient>();
            this.Load();
            AddPatientCommand = new Command(ExecuteAddPatientCommand);
        }

        public void Load()
        {
            var patients = database.ListPatients();
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
