using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FeedingAddQtdViewModel : BaseViewModel
    {
        private Feeding _feeding;
        public Feeding Feeding
        {
            get { return _feeding; }
            set { _feeding = value; }
        }
        public Command FinalStepCommand { get; }

        public FeedingAddQtdViewModel(Feeding Feeding)
        {
            this.Feeding = Feeding;
            FinalStepCommand = new Command(ExecuteFinalStepCommandAsync);
        }

        private async void ExecuteFinalStepCommandAsync()
        {
            await PushAsync<FeedingAddFoodTimeViewModel>(this.Feeding);
        }
    }
}
