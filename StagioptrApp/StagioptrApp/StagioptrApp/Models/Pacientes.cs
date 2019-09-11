using SQLite;

namespace StagioptrApp.Models
{
    [Table("Paciente")]
    public class Pacientes
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public string Name { get; set; }
        public string Birthday { get; set; }
        public string Status { get; set; }

        public string Details { get; set; }
    }
}
