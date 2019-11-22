using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class DrugsAddViewModel: BaseViewModel
    {
        
        DatabaseConnection database = new DatabaseConnection();
        public Command AddDrugsCommand { get; }
        public Command LogoutCommand { get; set; }

        private Drugs _drugs;
        public Drugs Drugs
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


        public DrugsAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            Drugs = new Drugs();
            LogoutCommand = new Command(this.Logout);
            AddDrugsCommand = new Command(ExecuteAddDrugsCommand);
        }

        private void ExecuteAddDrugsCommand()
        {
            this.Drugs.IdPatient = this.Patient.Id;
            this.Drugs.Patient = this.Patient;
            this.database.InsertDrugs(this.Drugs);
            Application.Current.MainPage.Navigation.PopAsync();
        }
    }
}
