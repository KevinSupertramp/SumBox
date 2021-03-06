-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Client: localhost
-- Généré le: Ven 22 Mars 2013 à 09:11
-- Version du serveur: 5.5.24-log
-- Version de PHP: 5.3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Base de données: `sumbox_auth`
--

-- --------------------------------------------------------

--
-- Structure de la table `account`
--

CREATE TABLE IF NOT EXISTS `account` (
  `account_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `pseudo` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `hash_password` varchar(45) COLLATE utf8_unicode_ci NOT NULL,
  `session_key` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(45) COLLATE utf8_unicode_ci NOT NULL,
  `gm_level` tinyint(3) unsigned NOT NULL,
  `secret_question` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `secret_answer` varchar(80) COLLATE utf8_unicode_ci NOT NULL,
  `join_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_login` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `last_ip` varchar(15) COLLATE utf8_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `banned` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `subscription_time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
  PRIMARY KEY (`account_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=2 ;

--
-- Contenu de la table `account`
--

INSERT INTO `account` (`account_id`, `username`, `pseudo`, `hash_password`, `session_key`, `email`, `gm_level`, `secret_question`, `secret_answer`, `join_date`, `last_login`, `last_ip`, `online`, `banned`, `subscription_time`) VALUES
(1, 'admin', 'administrateur', 'admin', 'XitWr2BC9IjafPqt', 'admin@sumbox', 3, 'Quel est ton pseudo ?', 'administrateur', '2013-03-19 20:05:01', '0000-00-00 00:00:00', '127.0.0.1', 0, 0, '0000-00-00 00:00:00');

-- --------------------------------------------------------


--
-- Structure de la table `realm_characters`
--

CREATE TABLE IF NOT EXISTS `realm_characters` (
  `realm_id` int(10) unsigned NOT NULL DEFAULT '0',
  `account_id` int(10) unsigned NOT NULL,
  `num_characters` tinyint(3) unsigned NOT NULL DEFAULT '0'
  PRIMARY KEY (`realm_id`,`account_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci
-- --------------------------------------------------------

--
-- Structure de la table `ip_banned`
--

CREATE TABLE IF NOT EXISTS `ip_banned` (
  `ip` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `ban_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ban_reason` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `banned_by` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `unban_date` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `realmlist`
--

CREATE TABLE IF NOT EXISTS `realmlist` (
  `realm_id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `address` varchar(15) COLLATE utf8_unicode_ci NOT NULL DEFAULT '127.0.0.1',
  `port` smallint(5) unsigned NOT NULL DEFAULT '5555',
  `population` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `status` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `subscription` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `security_access_level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`realm_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=2 ;

--
-- Contenu de la table `realmlist`
--

INSERT INTO `realmlist` (`realm_id`, `address`, `port`, `population`, `status`, `subscription`, `security_access_level`) VALUES
(1, '127.0.0.1', 5555, 1, 1, 1, 0);
