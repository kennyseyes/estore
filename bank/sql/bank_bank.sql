-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: bank
-- ------------------------------------------------------
-- Server version	5.7.19-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `bank`
--

DROP TABLE IF EXISTS `bank`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bank` (
  `name` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `id` varchar(7) COLLATE utf8_unicode_ci DEFAULT NULL,
  `passwd` varchar(6) COLLATE utf8_unicode_ci DEFAULT NULL,
  `bank_name` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `question` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `answer` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `money` float DEFAULT NULL,
  `log` longtext COLLATE utf8_unicode_ci,
  `phone` varchar(11) COLLATE utf8_unicode_ci DEFAULT NULL,
  `card_no` varchar(4) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`card_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bank`
--

LOCK TABLES `bank` WRITE;
/*!40000 ALTER TABLE `bank` DISABLE KEYS */;
INSERT INTO `bank` VALUES ('王小明','1111111','111111','中国农业银行','你宠物的名字？','多多',5418.4,'WITHDRAW:取出1元 TRANSFER:转账11元给0002 SAVE:存入1元 ','11111111111','0001'),('周杰伦','2222222','222222','中国工商银行','你母亲的名字？','妈妈',41,'RECEIVE:收到转账11元从0001 ','22222222222','0002'),('李易峰','3333333','333333','中国建设银行','你父亲的名字？','爸爸',1635.09,NULL,'33333333333','0003'),('Alexander Wang','4444444','444444','中国建设银行','你最喜欢的人？','人',33333,NULL,'44444444444','0004'),('Misha Collins','5555555','555555','中国工商银行','你父亲的名字？','爸爸',9988.3,NULL,'55555555555','0005');
/*!40000 ALTER TABLE `bank` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-10-05 11:33:59
