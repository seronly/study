-- MySQL dump 10.13  Distrib 5.5.23, for Win64 (x86)
--
-- Host: localhost    Database: db1
-- ------------------------------------------------------
-- Server version	5.5.23
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `db1`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `db1` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `db1`;

--
-- Table structure for table `fouls`
--

DROP TABLE IF EXISTS `fouls`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `fouls`
(
  `FIO` varchar
(30) NOT NULL,
  `Birthday` date NOT NULL,
  `Address` varchar
(255) NOT NULL,
  `NumCar` varchar
(10) NOT NULL,
  `InspectorFIO` varchar
(30) NOT NULL,
  `Station` int
(11) NOT NULL,
  `FoulDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `fouls`
--

LOCK TABLES `fouls` WRITE;
/*!40000 ALTER TABLE `fouls` DISABLE KEYS */;
INSERT INTO `
fouls`
VALUES
  ('╦Ж┬в┬а┬н┬о┬в ┼╜.╦Ж.', '1985-04-20', '╞Т┬а┬г┬а├а┬и┬н┬а 32-7', 'тВм678┼атАж', '┬П┬е├в├а┬о┬в ┼╜.╦Ж.', 1, '2017-04-11');
/*!40000 ALTER TABLE `fouls` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `groups`
--

DROP TABLE IF EXISTS `groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `groups`
(
  `NumGroup` int
(11) NOT NULL,
  `Faculty` varchar
(256) NOT NULL,
  `IDSt` int
(11) NOT NULL,
  PRIMARY KEY
(`NumGroup`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `groups`
--

LOCK TABLES `groups` WRITE;
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students`
--

DROP TABLE IF EXISTS `students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `students`
(
  `ID` int
(11) NOT NULL AUTO_INCREMENT,
  `FIO` varchar
(30) NOT NULL,
  `Birthday` date NOT NULL,
  `NumGroup` int
(11) NOT NULL,
  `Gender` varchar
(20) DEFAULT NULL,
  PRIMARY KEY
(`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students`
--

LOCK TABLES `students` WRITE;
/*!40000 ALTER TABLE `students` DISABLE KEYS */;
/*!40000 ALTER TABLE `students` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'db1'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-02-21 18:35:28
