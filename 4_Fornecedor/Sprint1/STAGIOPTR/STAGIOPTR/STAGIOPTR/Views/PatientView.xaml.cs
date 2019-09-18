using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientView : ContentPage
    {
        private readonly PatientViewModel _viewModel;
        public PatientView()
        {
            InitializeComponent();
            BindingContext = _viewModel;
        }
    }
}