using STAGIOPTR.ViewModels;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PatientDeleteView : ContentPage
    {
        private readonly PatientDeleteViewModel _viewModel;
        public PatientDeleteView()
        {
            InitializeComponent();
            _viewModel = new PatientDeleteViewModel();
            BindingContext = _viewModel;
        }
    }
}