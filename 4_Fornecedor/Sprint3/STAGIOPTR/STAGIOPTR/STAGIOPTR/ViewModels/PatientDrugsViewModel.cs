using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class PatientDrugsViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private ObservableCollection<Drugs> _drugs;

        public ObservableCollection<Drugs> Drugs
        {
            get { return _drugs; }
            set { SetProperty(ref _drugs, value); }
        }

        private Patient _patient;

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        public Command AddDrugsCommand { get; }
        public Command LoadDrugsCommand { get; }
        public Command<Drugs> ShowDrugsCommand { get; }
        public Command LogoutCommand { get; }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        public PatientDrugsViewModel()
        {
            User User = database.GetLoggedUser();
            this.Patient = database.GetPatientPerId(User.IdPatient);
            Drugs = new ObservableCollection<Drugs>();
            this.IsLoading = true;
            _ = this.LoadAsync();
            AddDrugsCommand = new Command(ExecuteAddDrugsCommand);
            ShowDrugsCommand = new Command<Drugs>(ExecuteShowDrugsCommand);
            LoadDrugsCommand = new Command(LoadAsyncList);
            LogoutCommand = new Command(this.Logout);
        }

        private async void ExecuteAddDrugsCommand()
        {
            await PushAsync<DrugsAddViewModel>(this.Patient);
        }

        private async void ExecuteShowDrugsCommand(Drugs Drugs)
        {
            await PushAsync<PatientViewModel>(Patient);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var drugs = database.GetDrugs(this.Patient.Id);
            this.Drugs.Clear();
            foreach (var drug in drugs)
            {
                this.Drugs.Add(drug);
            }
            this.IsLoading = false;
        }

        public void DeleteDrugsCommand(Drugs Drugs)
        {
            this.database.DeleteDrugs(Drugs);
            this.Drugs.Remove(Drugs);
        }
    }
}
