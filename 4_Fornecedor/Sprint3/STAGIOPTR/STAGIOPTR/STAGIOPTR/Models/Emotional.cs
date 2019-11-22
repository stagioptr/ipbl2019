using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Emotional")]
    public class Emotional
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Indexed]
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
        [NotNull]
        public DateTime EmotionalTime { get; set; }
        [NotNull]
        public int Quality { get; set; } 
    }
}
