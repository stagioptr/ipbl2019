using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using StagioptrApp.Models;
using StagioptrApp.ViewModels;

namespace StagioptrApp.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PacienteInsertPage : ContentPage
    {
        private PacienteInsertViewModel _pacientesInsertViewModel = new PacienteInsertViewModel();
        public PacienteInsertPage()
        {
            InitializeComponent();
            BindingContext = _pacientesInsertViewModel;
        }

        private void SalvarAction(object sender, EventArgs e)
        {
            Pacientes paciente = new Pacientes();
            paciente.Name = name.Text;
            paciente.Birthday = birthday.Text;
            paciente.Status = status.Text;
            paciente.Details = details.Text;
            _pacientesInsertViewModel.Add(paciente);
            Navigation.PopAsync();
        }
    }
}