using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Patient")]
    public class Patient
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [NotNull]
        public string Name { get; set; }
        [Unique, NotNull]
        public string CPF { get; set; }
        [NotNull]
        public DateTime Birthdate { get; set; }
        public string BloodType { get; set; }
        public string Gender { get; set; }
        [Unique]
        public string Email { get; set; }
        [NotNull]
        public string EmergencyPhone { get; set; }
    }
}
