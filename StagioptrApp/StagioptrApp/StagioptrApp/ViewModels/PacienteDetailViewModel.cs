using StagioptrApp.Database;
using StagioptrApp.Models;

namespace StagioptrApp.ViewModels
{
    public class PacienteDetailViewModel
    {
        public Pacientes paciente { get; set; }
        DatabaseConnection database = new DatabaseConnection();

        public PacienteDetailViewModel()
        {

        }
    }
}
