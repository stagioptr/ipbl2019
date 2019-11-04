using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class SleepAddViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        private Patient _patient;

        public Command AddSleepCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        private Sleep _sleep;

        public Sleep Sleep
        {
            get { return _sleep; }
            set { SetProperty(ref _sleep, value); }
        }


        public SleepAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Sleep = new Sleep();
            AddSleepCommand = new Command(ExecuteAddSleepCommand);
        }

        public void ExecuteAddSleepCommand()
        {
            this.Sleep.IdPatient = this.Patient.Id;
            this.database.InsertSleep(this.Sleep);
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }
    }
}
