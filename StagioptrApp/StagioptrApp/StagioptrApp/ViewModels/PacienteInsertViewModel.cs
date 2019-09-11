using StagioptrApp.Database;
using StagioptrApp.Models;

namespace StagioptrApp.ViewModels
{
    class PacienteInsertViewModel
    {
        public Pacientes paciente { get; set; }
        DatabaseConnection database = new DatabaseConnection();

        public PacienteInsertViewModel()
        {

        }

        public void Add(Pacientes paciente)
        {
            this.database.InsertPacientes(paciente);
        }

    }
}
