using StagioptrApp.ViewModels;
using System;
using System.Collections;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using StagioptrApp.Models;

namespace StagioptrApp.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PacientesPage : ContentPage
    {
        private PacientesViewModel _pacientesViewModel = new PacientesViewModel();
        public PacientesPage()
        {
            InitializeComponent();
            BindingContext = _pacientesViewModel;
            //teste
            _pacientesViewModel.Load();
        }

        async void Button_Clicked(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new PacienteInsertPage());
        }

        async void AlterAction(object sender, EventArgs e)
        {
            var menuItem = sender as MenuItem;
            Pacientes paciente = menuItem.CommandParameter as Pacientes;
            await Navigation.PushAsync(new PacienteAlterPage(paciente));
        }

        public void DeleteAction(object sender, EventArgs e)
        {
            var menuItem = sender as MenuItem;
            Pacientes paciente = menuItem.CommandParameter as Pacientes;
            _pacientesViewModel.Delete(paciente);
        }

    }
}