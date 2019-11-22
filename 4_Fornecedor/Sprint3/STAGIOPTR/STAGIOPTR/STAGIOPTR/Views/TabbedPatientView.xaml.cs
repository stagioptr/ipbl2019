using STAGIOPTR.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class TabbedPatientView : TabbedPage
    {
        private readonly TabbedPatientViewModel _viewModel;

        public TabbedPatientView()
        {
            InitializeComponent();
            _viewModel = new TabbedPatientViewModel();
            BindingContext = _viewModel;
        }
    }
}