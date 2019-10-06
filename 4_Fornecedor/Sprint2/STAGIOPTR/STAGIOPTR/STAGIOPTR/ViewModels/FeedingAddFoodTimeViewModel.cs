using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FeedingAddFoodTimeViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();

        private Feeding _feeding;

        public Feeding Feeding
        {
            get { return _feeding; }
            set { _feeding = value; }
        }

        private string _patientName;

        public string PatientName
        {
            get { return _patientName; }
            set { SetProperty(ref _patientName, value); }
        }

        public Command FeedingAddCommand { get; }

        public FeedingAddFoodTimeViewModel(Feeding Feeding)
        {
            this.Feeding = Feeding;
            PatientName = database.getPatientPerId(Feeding.IdPatient).Name;
            FeedingAddCommand = new Command(ExecuteFeedingAddCommand);
        }

        public void ExecuteFeedingAddCommand()
        {
            this.database.InsertFeeding(this.Feeding);
            Application.Current.MainPage.Navigation.PopToRootAsync();
        }

    }
}
