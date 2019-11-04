using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Emotional")]
    public class Emotional
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public int IdPatient { get; set; }
        public DateTime EmotionalTime { get; set; }
        public string Quality { get; set; }
    }
}
