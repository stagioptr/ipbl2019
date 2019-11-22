using System;
using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;

namespace STAGIOPTR.MongoModels
{
    public class EmergencyTopic
    {
        [BsonId()]
        public ObjectId Id { get; set; }
        [BsonElement("Id")]
        [BsonRequired()]
        public string IdPatient { get; set; }
        [BsonElement("dataHora")]
        [BsonRequired()]
        public DateTime DataHora { get; set; }
        [BsonElement("latitude")]
        [BsonRequired()]
        public double Latitude { get; set; }
        [BsonElement("longitude")]
        [BsonRequired()]
        public double Longitude { get; set; }
        [BsonElement("altitude")]
        [BsonRequired()]
        public double Altitude { get; set; }
    }
}
