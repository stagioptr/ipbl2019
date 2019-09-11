using System;
using StagioptrApp.Models;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace StagioptrApp.Views
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class PacienteAlterPage : ContentPage
    {
        public PacienteAlterPage(Pacientes paciente)
        {
            InitializeComponent();
        }

        public void AlterAction(Object sender, EventArgs e)
        {

        }
    }
}