using MongoDB.Bson;
using MongoDB.Driver;
using System;
using Newtonsoft.Json;
using STAGIOPTR.MongoModels;
using System.Linq.Expressions;
using System.Collections.Generic;
using System.Linq;

namespace STAGIOPTR.Database
{
    public class MongoDatabase
    {
        private IMongoDatabase database;
        private IMongoCollection<EmergencyTopic> EmergencyCollection;
        private IMongoCollection<SensorTopic> SensorCollection;
        private IMongoCollection<FeedingTopic> FeedingCollection;
        private IMongoCollection<SleepTopic> SleepCollection;
        private IMongoCollection<EmotionalTopic> EmotionalCollection;
        public MongoDatabase()
        {
            var client = new MongoClient("mongodb://stagioptr:ipbl2019@34.68.34.160:27017");
            database = client.GetDatabase("stagioptr");
            this.EmergencyCollection = database.GetCollection<EmergencyTopic>("emergency");
            this.SensorCollection = database.GetCollection<SensorTopic>("sensor");
            this.FeedingCollection = database.GetCollection<FeedingTopic>("feeding");
            this.SleepCollection = database.GetCollection<SleepTopic>("sleep");
            this.EmotionalCollection = database.GetCollection<EmotionalTopic>("emotional");
        }

        public void InsertEmergency(EmergencyTopic EmergencyTopic)
        {
            this.EmergencyCollection.InsertOne(EmergencyTopic);
        }


        public void InsertSensor(SensorTopic SensorTopic)
        {
            this.SensorCollection.InsertOne(SensorTopic);
        }

        public void InsertFeeding(FeedingTopic FeedingTopic)
        {
            this.FeedingCollection.InsertOne(FeedingTopic);
        }
        public void InsertSleep(SleepTopic SleepTopic)
        {
            this.SleepCollection.InsertOne(SleepTopic);
        }

        public void InsertEmotional(EmotionalTopic EmotionalTopic)
        {
            this.EmotionalCollection.InsertOne(EmotionalTopic);
        }



    }
}
