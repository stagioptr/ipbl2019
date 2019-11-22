using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class TabbedPatientViewModel : BaseViewModel
    {
        public Command LogoutCommand { get; set; }

        public TabbedPatientViewModel()
        {
            LogoutCommand = new Command(this.Logout);
        }
    }
}
