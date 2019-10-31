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
        public Command LogoutCommand { get; set; }
        public Command VerySatisfiedCommand { get; }
        public Command SatisfiedCommand { get; }
        public Command NormalCommand { get; }
        public Command DissatisfiedCommand { get; }
        public Command VeryDissatisfiedCommand { get; }

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

        private TimeSpan _sleepTime;    

        public TimeSpan SleepTime
        {
            get { return _sleepTime; }
            set { _sleepTime = value; }
        }


        public SleepAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Sleep = new Sleep();
            this.Sleep.SleepTime = DateTime.Now;
            this.SleepTime = DateTime.Now.TimeOfDay;
            LogoutCommand = new Command(this.Logout);
            VerySatisfiedCommand = new Command(ExecuteVerySatisfiedCommand);
            SatisfiedCommand = new Command(ExecuteSatisfiedCommand);
            NormalCommand = new Command(ExecuteNormalCommand);
            DissatisfiedCommand = new Command(ExecuteDissatisfiedCommand);
            VeryDissatisfiedCommand = new Command(ExecuteVeryDissatisfiedCommand);
        }

        public void ExecuteAddSleepCommand()
        {
            this.Sleep.SleepTime = this.Sleep.SleepTime.Add(this.SleepTime);
            this.Sleep.IdPatient = this.Patient.Id;
            this.database.InsertSleep(this.Sleep);
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }

        public void ExecuteVerySatisfiedCommand()
        {
            this.Sleep.Quality = "Ótimo";
            this.ExecuteAddSleepCommand();
        }

        public void ExecuteSatisfiedCommand()
        {
            this.Sleep.Quality = "Bom";
            this.ExecuteAddSleepCommand();
        }

        public void ExecuteNormalCommand()
        {
            this.Sleep.Quality = "Regular";
            this.ExecuteAddSleepCommand();
        }

        public void ExecuteDissatisfiedCommand()
        {
            this.Sleep.Quality = "Ruim";
            this.ExecuteAddSleepCommand();
        }

        public void ExecuteVeryDissatisfiedCommand()
        {
            this.Sleep.Quality = "Péssimo";
            this.ExecuteAddSleepCommand();
        }
    }
}
