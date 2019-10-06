using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Sleep")]
    public class Sleep
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Indexed]
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
        public DateTime SleepTime { get; set; } 
        public float Duration { get; set; }
        public string Quality { get; set; }
    }
}
