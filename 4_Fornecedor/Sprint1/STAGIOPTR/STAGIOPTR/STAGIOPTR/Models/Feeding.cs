using System;
using SQLite;

namespace STAGIOPTR.Models
{
    [Table("Feeding")]
    public class Feeding
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public int IdPatient { get; set; }
        public int IdFood { get; set; }
        public int qtd { get; set; }
        public DateTime FoodTime { get; set; }
    }
}
