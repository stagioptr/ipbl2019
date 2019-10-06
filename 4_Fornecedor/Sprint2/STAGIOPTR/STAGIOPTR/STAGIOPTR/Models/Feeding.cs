using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Feeding")]
    public class Feeding
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        [Indexed]
        public int IdPatient { get; set; }
        [Ignore]
        public Patient Patient { get; set; }
        [Indexed]
        public int IdFood { get; set; }
        [Ignore]
        public string Food { get; set; }
        public int qtd { get; set; }
        public DateTime FoodTime { get; set; }
    }
}
