<?php
/**
 * @file
 * intel_ea_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function intel_ea_feature_default_rules_configuration() {
  $items = array();
  $items['rules_general_membership_application_email_admin'] = entity_import('rules_config', '{ "rules_general_membership_application_email_admin" : {
      "LABEL" : "General Membership Application: Email Admin",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entityform submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Submitted Entityform", "type" : "entityform" },
        "entityform_type" : { "label" : "Entityform Type", "type" : "entityform_type" }
      },
      "IF" : [
        { "component_rules_submitted_entityform_notify" : { "entityform" : [ "entityform" ] } },
        { "NOT data_is_empty" : { "data" : [ "entityform-type:notify-emails" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[entityform-type:notify-emails]",
            "subject" : "Intel\\u00ae Internet of Things Solutions Alliance: General Membership Submission",
            "message" : "[entityform:entityform-submittd-data]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_general_membership_application_email_submitter'] = entity_import('rules_config', '{ "rules_general_membership_application_email_submitter" : {
      "LABEL" : "General Membership Application: Email Submitter",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entityform submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Submitted Entityform", "type" : "entityform" },
        "entityform_type" : { "label" : "Entityform Type", "type" : "entityform_type" }
      },
      "IF" : [
        { "component_rules_submitted_entityform_notify" : { "entityform" : [ "entityform" ] } },
        { "NOT data_is_empty" : { "data" : [ "entityform-type:notify-emails" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[entityform:field-gma-email-address], embedded.alliance.general.membership@intel.com",
            "subject" : "Application for [entityform:field-gma-company-name] at [site:name]",
            "message" : "[entityform:field-gma-first-name] [entityform:field-gma-last-name],\\r\\n\\r\\nThank you for your application to [site:name]. We will respond to your application within 15 business days. We may respond with questions if we are unclear about anything in the application. If you have questions, please contact embedded.alliance.general.membership@intel.com.\\r\\n\\r\\nThank You,\\r\\n[site:name] Administration",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_login_redirect'] = entity_import('rules_config', '{ "rules_login_redirect" : {
      "LABEL" : "Login redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT text_matches" : { "text" : [ "site:current-page:url" ], "match" : "reset" } }
      ],
      "DO" : [ { "redirect" : { "url" : "member-resource-center" } } ]
    }
  }');
  $items['rules_membership_renewal_application_email_admin'] = entity_import('rules_config', '{ "rules_membership_renewal_application_email_admin" : {
      "LABEL" : "Membership Renewal Application: Email Admin",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entityform submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Submitted Entityform", "type" : "entityform" },
        "entityform_type" : { "label" : "Entityform Type", "type" : "entityform_type" }
      },
      "IF" : [
        { "component_rules_submitted_entityform_notify" : { "entityform" : [ "entityform" ] } },
        { "NOT data_is_empty" : { "data" : [ "entityform-type:notify-emails" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[entityform-type:notify-emails]",
            "subject" : "Intel\\u00ae Internet of Things Solutions Alliance: Membership Renewal Submission",
            "message" : "[entityform:entityform-submittd-data]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
