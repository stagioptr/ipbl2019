using StagioptrApp.Models;
using StagioptrApp.ViewModels;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace StagioptrApp.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PacienteDetailPage : ContentPage
    {
        private PacientesViewModel _pacientesViewModel = new PacientesViewModel();
        public PacienteDetailPage(Pacientes paciente)
        {
            InitializeComponent();
            BindingContext = _pacientesViewModel;
        }
    }
}