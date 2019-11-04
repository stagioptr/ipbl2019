using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class EmotionalAddViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        private Patient _patient;

        public Command AddEmotionalCommand { get; }

        public Patient Patient
        {
            get { return _patient; }
            set { SetProperty(ref _patient, value); }
        }

        private Emotional emotional;

        public Emotional Emotional
        {
            get { return emotional; }
            set { SetProperty(ref emotional, value); }
        }


        public EmotionalAddViewModel(Patient Patient)
        {
            this.Patient = Patient;
            this.Emotional = new Emotional();
            AddEmotionalCommand = new Command(ExecuteAddEmotionalCommand);
        }

        public void ExecuteAddEmotionalCommand()
        {
            this.Emotional.IdPatient = this.Patient.Id;
            this.database.InsertEmotional(this.Emotional);
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }

    }
}
