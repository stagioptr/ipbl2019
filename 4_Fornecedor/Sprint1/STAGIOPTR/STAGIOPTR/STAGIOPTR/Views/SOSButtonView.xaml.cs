using STAGIOPTR.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace STAGIOPTR.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class SOSButtonView : ContentPage
    {
        private readonly SOSButtonViewModel _viewModel;
        public SOSButtonView()
        {
            InitializeComponent();
        }
    }
}