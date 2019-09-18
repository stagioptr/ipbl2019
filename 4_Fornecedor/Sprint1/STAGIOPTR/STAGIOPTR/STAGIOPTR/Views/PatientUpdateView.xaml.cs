using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientUpdateView : ContentPage
    {
        private readonly PatientUpdateViewModel _viewModel;
        public PatientUpdateView()
        {
            InitializeComponent();
            _viewModel = new PatientUpdateViewModel();
            BindingContext = _viewModel;
        }
    }
}