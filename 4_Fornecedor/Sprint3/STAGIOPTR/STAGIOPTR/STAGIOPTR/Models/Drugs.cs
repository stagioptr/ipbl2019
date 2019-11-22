using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Drugs")]
    public class Drugs
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Indexed]
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
        [NotNull]
        public string Name { get; set; }
        public DateTime Start { get; set; }
        public int Period { get; set; }
        [NotNull]
        public int Qtd { get; set; }
        public string Comments { get; set; }
    }
}