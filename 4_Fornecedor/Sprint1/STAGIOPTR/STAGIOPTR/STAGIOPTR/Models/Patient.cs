using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Patient")]
    public class Patient
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public string Name { get; set; }
        public DateTime Birthday { get; set; }
        public string BloodType { get; set; }
        public string Email { get; set; }
        public string Gender { get; set; }

    }
}
