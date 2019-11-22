using System;
using System.Collections.Generic;
using System.Text;

namespace STAGIOPTR.ViewModels
{
    public class DashboardViewModel: BaseViewModel
    {
        private string _urlDashboard;

        public string UrlDashboard
        {
            get { return _urlDashboard; }
            set { _urlDashboard = value; }
        }

        public DashboardViewModel()
        {
            this.UrlDashboard = "http://34.68.34.160:5010/dash/paciente/";
        }

    }
}
