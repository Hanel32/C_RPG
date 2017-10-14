#include <stdio.h>
#include <conio.h>
#include <conio.c>
#include <stdlib.h>

  int gold    = 100;                              //Gold pouch
  int ski     = 10;                               //base skill for obstacles
  int job     = 0;                                //Job
  int quest, type, rid, path;                     //Decisions
  int hit, dmgGiven, dmgTaken, spider, spiderDmg; //Combat
  int health = 0, attack = 0, skill = 0;          //Potion names
  int hp, maxhp, attk, acc;                       //Skill names
  int weap, arm, pot;                             //Item types
  char cont, desi, go = 'y';                      //Loop modifiers
  int welcome(),        ranger(),      warrior(),    mage();
  int questHub(),       merchant(),    resume(),     potions();
  int healthPot(),      attackPot(),   badSelect(),  potionDrink();
  int skillPot(),       abstain(),     weapons(),    getSword();
  int getWand(),        getKnife(),    armors(),     metalArmor();
  int hideArmor(),      riddle(),      riddleGood(), riddleBad();
  int forestQuest(),    darkHollow(),  firstFight(), forest();
  int clothArmor(),     rangerFight(), mageFight(),  warriorFight();
  int secondCorridor(), secondFight();
  
  
int main()
{ 
  textcolor(4);
  {
  welcome();
  }
  while(go == 'y' || go == 'Y')
  {
    switch(job)
    {
      case 1://Ranger
      {
        ranger();
        break;
      }
      case 2: //Warrior
      {
        warrior();
        break;
      }
      case 3: //Mage
      {
        mage();
        break;
      }
      default:
      {
        while(job != 1 && job !=2 && job !=3)
        {
          badSelect();
          scanf("%d", &job);
        }
      }
    }
  }
  { 
    resume();
  }
  while(cont == 'y' || cont == 'Y') //Begins the questing dialogue
  {
    questHub();  //The main city quest hub
  while (quest != 1 && quest != 2 && quest != 3)//invalid check
  {
    badSelect();
    scanf("%d", &quest);
  }
  if(quest == 1) //The choice to talk to the merchant starts here
  {            
    merchant();  //The Merchant's shop
      if(type == 1)     //Potion Selection
      {
        potions();
        while(pot != 1 && pot != 2 && pot != 3 && pot != 4)//invalid check
        {
          badSelect();
          scanf("%d", &pot);
        }
        if(pot == 1)      //Health potion buy option
        {
          healthPot();
          continue;
        }
        else if(pot == 2) //Attack potion buy option
        {
          attackPot();
          continue;
        }
        else if(pot == 3) //Skill potion buy option
        {
          skillPot();
          continue;
        }
        else if(pot == 4) //Nothing for me, sir.
        {
          abstain();
          resume();
          continue;
        }
      }
      if (type == 2)      //Weapon Selection
      {
        weapons();
      while(weap != 1 && weap != 2 && weap != 3 && weap != 4)//invalid check
      {
        badSelect();
        scanf("%d", &weap);
      }
      if(weap == 1)        //Sword buy option
      {
        getSword();
        continue;
      }
      else if(weap == 2)   //Wand buy option
      {
        getWand();
        continue;
      }
      else if(weap == 3)   //Knife buy option
      {
        getKnife();
        continue;
      }
      else if(weap == 4)   //None for me today. thanks
      {
        abstain();
        resume();
        continue;
      }
    }
    if (type == 3)
    {
      armors();
      while(arm != 1 && arm != 2 && arm != 3 && arm != 4)//invalid check
      {
        badSelect();
        scanf("%d", &arm);
      }
      if(arm == 1)        //Metal buy option
      {
        metalArmor();
        continue;
      }
      else if(arm == 2)   //Hide buy option
      {
        hideArmor();
        continue;
      }
      else if(arm == 3)   //Cloth buy option
      {
        clothArmor();
        continue;
      }
      else if(arm == 4)   //None for me today. thanks
      {
        abstain();
        resume();
        continue;
      }
    } 
  } 
  if(quest == 2)              //decision to go to the forrest
  {
    {
      riddle();
      while (rid != 2)        //incorrect riddle answer message
      {
        riddleBad();
      }
      if(rid == 2)          //correct riddle answer message
      {
        riddleGood();
        while(cont == 'y' || cont == 'Y')     //start quest dialogue for forest
        {
          forestQuest();
          if(path == 1)
          {
            darkHollow();
            if(quest == 1)
            {
              break;
            }
            if(quest == 2)
            {
              firstFight();
              if(quest == 1)
              {
                break;
              }
              if(quest == 2)
              {
                spider = 10;
                while(cont == 'y' || cont == 'Y' && spider > 0)
                  switch(job)
                  {
                    case 1: //Ranger fights the Spider
                    {
                      rangerFight();
                      break;
                    }
                    case 2: //Warrior fights the Spider
                    {
                      warriorFight();
                      break;
                    }
                    case 3: //Mage fights the Spider
                    {
                      mageFight();
                      break;
                    }
                  }
                }
                secondCorridor();
                if(quest == 2)
                {
                  secondFight();
                  switch(quest)
                  {
                  case 1:
                    {
                      potionDrink();
                    }
                    case 2:
                    {
                      printf("\n\n     You choose to start your combat with defence.");
                      printf("\n     You manage to quickly crawl into a small hole, too");
                      printf("\n     small for your arachnid attackers, and heal 5 hp.");
                      hp = hp + 5;
                      printf("\n     Your health is now %d/%d", hp, maxhp);
                      printf("\n\n     Good Luck!");
                      printf("\n\n     Press any key to fight");
                      getch();
                      break;
                    }
                    case 3:
                    {
                      printf("\n\n     You are no fool! You jump towards the spider with");
                      printf("\n     your weapon drawn. Today, these spiders dine in hell!");
                      getch();
                      break;
                    }
                    default:
                    {
                      printf("\n\n     Somehow, you manage to not make up your mind.");
                      printf("\n     While you are confused, the spiders manage to");
                      printf("\n     deal 5 damage to you. An awful start!");
                      hp = hp - 5;
                      getch();
                      break;
                    }
                  }
                spider = 30;
                cont = 'y';
                while(cont == 'y' || cont == 'Y' && spider > 0)
                {
                  switch(job)
                  {
                    case 1: //Ranger fights the Spider
                    {
                      printf("\n     You run towards the spiders and attack with your bow!");
                      hit = (rand()%20) + acc + 5;
                      printf("\n     Your roll for hit chance with accuracy is: %d", hit);
                      printf("\n     You have +5 accuracy due to the number of spiders.");
                      printf("\n     The spider's armor provides 15 points of protection.");
                      if(hit >= 15) //Hit spider
                      {
                        dmgGiven = 0;
                        dmgGiven = (rand()%attk);
                        printf("\n     You do %d damage to the spiders!", dmgGiven);
                        spider = ((spider) - dmgGiven);
                        if(spider > 20)
                        {
                          printf("\n     Your arrow lodges deep into one of the spiders!");
                          printf("\n     The spider trio's health is now: %d/30", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The third spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          printf("\n\n     Continue? (Y/N): ");
                          scanf("%s", &cont);
                          break;
                        }
                        else if(spider > 10 && spider <= 20) //Spider One Dies
                        {
                          printf("\n\n     You've killed one of the spiders!");                          
                          printf("\n     Your arrow lodges deep into one of the spiders!");
                          printf("\n     The spider duo's health is now: %d/20", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          printf("\n\n     Continue? (Y/N): ");
                          scanf("%s", &cont);
                          break;
                        }
                        else if(spider < 10)
                        {
                          printf("\n\n     You've killed another one of the spiders!");                          
                          printf("\n     Your arrow lodges deep into the last spider!");
                          printf("\n     The spider's health is now: %d/10", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;   
                          printf("\n\n     The lone spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                        }
                      }
                      else if(hit < 15 && spider > 20) //Miss spider trio
                      {
                        printf("\n     Your arrow misses the spiders alltogether!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The third spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                      else if(hit < 15 && spider < 20 && spider >= 10) //miss spider duo
                      {
                        printf("\n     Your arrow misses the spiders alltogether!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                      else if(hit < 15 && spider < 10) //miss spider singular
                      {
                        printf("\n     Your arrow misses the spider!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                    break;
                    }
                    case 2: //Warrior fights the Spider
                    {
                      printf("\n     You run towards the spiders and attack with your axe!");
                      hit = (rand()%20) + acc + 5;
                      printf("\n     Your roll for hit chance with accuracy is: %d", hit);
                      printf("\n     You have +5 accuracy due to the number of spiders.");
                      printf("\n     The spider's armor provides 15 points of protection.");
                      if(hit >= 15) //Hit spider
                      {
                        dmgGiven = 0;
                        dmgGiven = (rand()%attk);
                        printf("\n     You do %d damage to the spiders!", dmgGiven);
                        spider = ((spider) - dmgGiven);
                        if(spider > 20)
                        {
                          printf("\n     Your axe sinks into one of the spiders!");
                          printf("\n     The spider trio's health is now: %d/30", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The third spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          printf("\n\n     Continue? (Y/N): ");
                          scanf("%s", &cont);
                          break;
                        }
                        else if(spider > 10 && spider <= 20) //Spider One Dies
                        {
                          printf("\n\n     You've killed one of the spiders!");                          
                          printf("\n     Your axe sinks into one of the spiders!");
                          printf("\n     The spider duo's health is now: %d/20", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          printf("\n\n     Continue? (Y/N): ");
                          scanf("%s", &cont);
                          break;
                        }
                        else if(spider < 10)
                        {
                          printf("\n\n     You've killed another one of the spiders!");                          
                          printf("\n     Your axe sinks into the last spider!");
                          printf("\n     The spider's health is now: %d/10", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;   
                          printf("\n\n     The lone spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                        }
                      }
                      else if(hit < 15 && spider > 20) //Miss spider trio
                      {
                        printf("\n     Your axe misses the spiders alltogether!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The third spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                      else if(hit < 15 && spider < 20 && spider >= 10) //miss spider duo
                      {
                        printf("\n     Your axe misses the spiders alltogether!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                      else if(hit < 15 && spider < 10) //miss spider singular
                      {
                        printf("\n     Your axe misses the spider!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                    break;
                    }
                    case 3: //Mage fights the Spider
                    {
                      printf("\n     You run towards the spiders and attack with your staff!");
                      hit = (rand()%20) + acc + 5;
                      printf("\n     Your roll for hit chance with accuracy is: %d", hit);
                      printf("\n     You have +5 accuracy due to the number of spiders.");
                      printf("\n     The spider's armor provides 15 points of protection.");
                      if(hit >= 15) //Hit spider
                      {
                        dmgGiven = 0;
                        dmgGiven = (rand()%attk);
                        printf("\n     You do %d damage to the spiders!", dmgGiven);
                        spider = ((spider) - dmgGiven);
                        if(spider > 20)
                        {
                          printf("\n     Your spell crackles maliciously through one of the spiders!");
                          printf("\n     The spider trio's health is now: %d/30", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The third spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          printf("\n\n     Continue? (Y/N): ");
                          scanf("%s", &cont);
                          break;
                        }
                        else if(spider > 10 && spider <= 20) //Spider One Dies
                        {
                          printf("\n\n     You've killed one of the spiders!");                          
                          printf("\n     Your spell crackles maliciously through one of the spiders!");
                          printf("\n     The spider duo's health is now: %d/20", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;
                          printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                          printf("\n\n     Continue? (Y/N): ");
                          scanf("%s", &cont);
                          break;
                        }
                        else if(spider < 10)
                        {
                          printf("\n\n     You've killed another one of the spiders!");                          
                          printf("\n     Your spell crackles maliciously through the last spider!");
                          printf("\n     The spider's health is now: %d/10", spider);
                          spiderDmg = rand()%4;
                          hp = hp - spiderDmg;   
                          printf("\n\n     The lone spider deals %d damage to you!", spiderDmg);
                          printf("\n     Your health is now: %d/%d", hp, maxhp);
                        }
                      }
                      else if(hit < 15 && spider > 20) //Miss spider trio
                      {
                        printf("\n     Your spell misses the spiders alltogether!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The third spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                      else if(hit < 15 && spider < 20 && spider >= 10) //miss spider duo
                      {
                        printf("\n     Your spell misses the spiders alltogether!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The second spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                      else if(hit < 15 && spider < 10) //miss spider singular
                      {
                        printf("\n     Your spell misses the spider!");
                        spiderDmg = rand()%4;
                        hp = hp - spiderDmg;
                        printf("\n\n     The first spider deals %d damage to you!", spiderDmg);
                        printf("\n     Your health is now: %d/%d", hp, maxhp);
                        printf("\n\n     Continue? (Y/N): ");
                        scanf("%s", &cont);
                        break;
                      }
                    break;
                    }
                  }
                }
              }
              }
              if(quest != 2)
              {
                break;
              }
            }
          }
          if(path == 2)
          {
            system("cls");
            printf("\n\nThe Silken Fields");
          }
          if(path == 3)
          {
            system("cls");
            printf("\n\nSpiderling's Grove");
          }
        }
      }
    } 
  }
  if (quest == 3)
  {
  printf("\nThis is where you help the man.");
  }
  getch();
}
int welcome()
{
  printf("Welcome to Lamellon, traveller! It seems you've fallen from the sky!");
  printf("\nMy name is Brutus, and I am the innkeeper of this great city.");
  printf("\nIn these dark days, we have many uses for an adventurer. What did\n");
  printf("you say was your profession?");
  printf("\n\n       .-'''''."); //Brutus the Innkeeper text art
  printf("\n      /   \\    \\\n     /   / `\\__/\n     | .'  _  _|");
  printf("\n     \(\\    6  6 \n     | \\     \\ :");
  printf("\n     |  \\/~` /`\\)\t<Brutus the Innkeeper>");
  printf("\n      |\\   {= `/\n      | '.___.'\n  .'` \\    |_");
  printf("\n /       '-__ / `-");
  printf("\n\n1) Uhh, sir, I'm no adventurer.  (ranger)");
  printf("\n2) I am a mighty Warrior!        (melee )");
  printf("\n3) I am a cunning Sorcerrer!     (mage  )"); 
  printf("\n\nAnswer: ");
  scanf("%d", &job);
}
int ranger()
{        
  printf("\nBrutus: Aye lad! Take up this bow! You can be a ranger.");
  printf("\n\n\t(You take the beautifully carved oaken bow, unsure of )");
  printf("\n\t(what to do with it... You guess... Atleast, so far...)");
  printf("\n\nGame:   Your 'new job' is Ranger. While the practice may be mysterious");
  printf(",\n\trest assured, you have within yourself what it takes. Because of this,");
  printf("\n\tyour hitpoints have been set to 80. Your attack average, however, is");
  printf("\n\t12 points. You have what it takes. God speed.");
  maxhp   = 80;
  hp      = 80;
  attk    = 12;
  acc     = 10;
  go = 'n';
}
int warrior()
{
  printf("\nBrutus: Wew! A warrior! Tis been ages since we've seen one proper!");
  printf("\n\n\t(You smirk at him, confident in your power. Next to you is an axe)");
  printf("\n\t(which you brandish, ready for any challenges that may await.");
  printf("\n\nGame:   Your job is Warrior, and you attack with strength and");
  printf("\n\tvitality. Because of this, your hitpoints have been set to");
  printf("\n\t120. Your attack average is 8 points. Good luck, and God speed.");
  maxhp= 120;
  hp   = 120;
  attk = 8;
  acc  = 14;
  go = 'n';
}
int mage()
{
  printf("\nBrutus: Aye? A mage? I'm not fond of the likes of ye...");
  printf("\n\n\t(You grimace. The fool! You grab the staff next to you)");
  printf("\n\t(and head off to whomever is in charge...    Verily...)");
  printf("\n\nGame:   Your job is Mage, and you wield mighty spells.");
  printf("\n\tBecause of this, your intellect is set to 20, and your");
  printf("\n\thitpoints have been set to 100. Your attack average is");
  printf("\n\t10 points. Good luck, and God speed.");
  maxhp= 100;
  hp   = 100;
  attk = 10;
  acc  = 12;
  go = 'n';
}
int questHub()
{
  system("cls");                 //Clears the screen for a new menu.
  printf("\n________.    ._____________________________.                          ");
  printf("\n(///(////\\  ///(///(///(///(///(///(///(////\\                       ");
  printf("\n///(///(  \\///(///(///(///(///(///(///(///(  \\                      ");
  printf("\n//(///(   ///(///(///(///(///(///(///(///(   |                        ");
  printf("\n/(///(  .///(///(///(///(///(///(///(///(  . |                        ");
  printf("\n    | .' |  ___    ___    ___   _____  | .'| |                        ");
  printf("\n    | |.'| |_|_|  |_|_|  |_|_| |__|__| | |.' |                        ");
  printf("\n    | '  | |_|_|  |_|_|  |_|_| |__|__| | ' . ||'--:|___._______.________________");
  printf("__  |  .'|    __   _____    _ +++____  | .'| |  .|   .'    _/////////)");
  printf("\n__| | |.'|   |  | |__|__|  |_+++++___| ||.' .'.|   .'    _//////////||");
  printf("\n__| | '.'|   | .| |__|__|  |+++:++___| |' .'.|   .'     ////////////||");
  printf("\n____|.'  |___|__|___________++::+______|.'.|   .'      (|<Moe's>|)//||");
  printf("\n       .|   '-=-.'            :'       .|    .'        ||'/_____||/ ||");
  printf("\n     .|   '   .    <The Inn>  :      .|    .'         .||/______||  ||");
  printf("\n   .|   '   .                       .|   .'         .' | _______||  II");
  printf("\n  |'--'|==||'--'|'--'|'--'|'--'|'-'|   .'         .'., ||       ||,.     ");
  printf("\n======================================'         .'     II       II      +++");
  printf("\n                                              .'         '     '       +++++");
  printf("\n                                              '''''''''''     '   +   +++:++");
  printf("\n================================.                            ' ;      ++::+");
  printf("\n   +   +       +       +      .'         .'''''''''''''''''''           :'");
  printf("\n    ;     '    '+   +       .'         .'   +     '    ,       +        :\n");
  printf("________________________________________________________________________________");
  printf("\nYou open a weathered spruce door, and step out of the damp");
  printf("\nof the inn, into the half-light of the morning. Birds chirp h-");
  printf("\nappily around you. In front of you, you see a merchant, aswell");
  printf("\nas several pathways. In which direction will start questing?");
  printf("\n\n\n\t1) The merchant seems like a good choice. (%d gold)", gold);
  printf("\n\t2) I see a path to a wooded forest. Time to adventure!");
  printf("\n\t3) There's a man that seems to be in need of help, I'll");
  printf("\n\t   go and see if he needs any assistance.");
  printf("\n\n\tAnswer: ");
  scanf("%d", &quest);
}
int merchant()
{
  system("cls");           //Clears the screen for a new menu
  printf("\n\n    You walk over to the merchant's stall to see what goods he offers.");
  printf("\n\n\t   Merchant: Welcome to my shop of wares! Have a look!\n", job);
  printf("\n\n\t   [-----[Moe's Adventuring Supplies]------]");
  printf("\n\n\t   [Potions]-----[Weapons]-----[Armor]-----]");
  printf("\n\n\t   [---------------------------------------]");
  printf("\n\n\t   [Health]------[Sword]-------[Metal]-----]");
  printf("\n\n\t   [Attack]------[Wand]--------[Hide]------]");
  printf("\n\n\t   [Skill]-------[Knife]-------[Cloth]-----]");
  printf("\n\n\t   [_______________________________________]");
  printf("\n\n\t   Please enter the type of item you would like");
  printf("\n\n    Enter (1) for potions, (2) for weapons, and (3) for armor: ");
  scanf("%d", &type);
}
int resume()
{
  printf("\n\nIf you would like to continue, push the 'y' button...");
  scanf("%s", &cont);
}
int potions()
{
  system("cls");
  printf("\nYou've chosen potions!\n");
  printf("\nWhich potion would you like?");
  printf("\n\n1)Health: Increases health by (10),        costs 10g.");
  printf("\n2)Attack: Increases attack by (5),         costs 50g.");
  printf("\n3)Skill : Increases agility skill by (10), costs 99g.\n");
  printf("4)No thank you, no purchases for me today.\n");
  printf("\nAnswer: ");
  scanf("%d", &pot);
}
int healthPot()
{
  gold = (gold - 10);
  health = (health + 1);
  printf("\nYou've chosen a health potion. (-10g)\n");
  printf("\nYou now have %d health potion(s).", health);
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\n\n\t\t   _____\n\t\t  `.___,'\n\t\t   (___)\n\t\t   <   >");
  printf("\n\t\t    ) (\n\t\t   /`-.\\\n\t\t  /     \\\n\t\t / _    _\\");
  printf("\n\t\t:,' `-.' `:\n\t\t|  HEALTH |\n\t\t:         ;");
  printf("\n\t\t \        /\n\t\t  `.___.' ");
  resume();
}
int badSelect()
{
  printf("\nInvalid selection. Pick again.");
  printf("\nAnswer: ");
}
int attackPot()
{
  gold = (gold - 50);
  attack = attack + 1;
  printf("\nYou've chosen an attack potion. (-50g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYou now have %i attack potion(s).", attack);
  printf("\n\n\t\t   _____\n\t\t  `.___,'\n\t\t   (___)\n\t\t   <   >");
  printf("\n\t\t    ) (\n\t\t   /`-.\\\n\t\t  /     \\\n\t\t / _    _\\");
  printf("\n\t\t:,' `-.' `:\n\t\t|  ATTACK |\n\t\t:         ;");
  printf("\n\t\t \        /\n\t\t  `.___.' ");
  resume();
}
int skillPot()
{
  gold  = (gold - 99);
  skill = skill + 1;
  printf("\nYou've chosen a skill potion. (-99g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYou now have %i agility potion(s).", skill);
  printf("\n\n\t\t   _____\n\t\t  `.___,'\n\t\t   (___)\n\t\t   <   >");
  printf("\n\t\t    ) (\n\t\t   /`-.\\\n\t\t  /     \\\n\t\t / _    _\\");
  printf("\n\t\t:,' `-.' `:\n\t\t|  SKILL  |\n\t\t:         ;");
  printf("\n\t\t \        /\n\t\t  `.___.' ");
  resume();
}
int abstain()
{
  printf("\nYou abstain from buying anything today.");
}
int weapons()
{
  system("cls");
  printf("You've chosen weapons!\n");
  printf("\nWhich weapon would you like?");
  printf("\n\n1)Sword: Increases total attack by 5. Costs 50g.");
  printf("\n2)Wand : Increases total attack by 4. Costs 40g.");
  printf("\n3)Knife: Increases total attack by 2. Costs 20g.");
  printf("\n4)No thank you. No purchases for me today.\n");
  printf("\nAnswer: ");
  scanf("%d", &weap);
}
int getSword()
{
  gold = (gold - 50);
  attk = (attk + 5);
  printf("\nYou've chosen a sword. (-50g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYour attack is now   : %d", attk);
  printf("\n\n                .v~");
  printf("\n               .(W");
  printf("\n              /lM.");
  printf("\n(-b__________/z@|\--------------------------------------------");
  printf("--------------.");
  printf("\n >@)$$$$$$$$($( )#H>==========================================");
  printf("==========----->");
  printf("\n(_p~~~~~~~~~~\z@|/--------------------------------------------");
  printf("--------------'");
  printf("\n              \lM`");
  printf("\n               `(B");
  printf("\n                 `?_");
  resume();
}
int getWand()
{
  gold = (gold - 40);
  attk = (attk + 4);
  printf("\nYou've chosen a wand. (-40g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYour attack is now   : %d", attk);
  printf("\n  .^.:.");
  printf("\n <.*.'::.  *     .*");
  printf("\n   |  .:''    .:'");
  printf("\n   |  '::.  .:'");
  printf("\n   |    ':::'    *");
  printf("\n * |     `*'");              
  resume();
}
int getKnife()
{
  gold = (gold - 20);
  attk = (attk + 2);
  printf("\nYou've chosen a Knife. (-20g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYour attack is now   : %4d", attk);
  printf("\n\n       O");
  printf("\n       |___________________");
  printf("\n0{XXXX}+====================>");
  printf("\n       |");
  printf("\n       O");
  resume();
}
int armors()
{
  system("cls");
  printf("You've chosen Armor!\n");
  printf("\nWhich armor would you like?");
  printf("\n\n1)Metal: Increases hp 10, decreases agility by 5. Costs 50g");
  printf("\n2)Hide : Increases hp 8 , increases agility by 5. Costs 50g");
  printf("\n3)Cloth: Increases hp 5 , increases agility by 8. Costs 50g");
  printf("\n4)No thank you. No purchases for me today.\n");
  printf("\nAnswer: ");
  scanf("%d", &arm);
}
int metalArmor()
{
  gold = (gold - 50);
  hp   = (hp + 10);
  skill= (skill - 5);
  printf("\nYou've chosen Metal armor. (-50g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYour health is now   : %4d", hp);
  printf("\nYour agility is now  : %4d", skill);
  resume();
}
int hideArmor()
{
  gold = (gold - 50);
  hp   = (hp + 8);
  skill= (skill + 5);
  printf("\nYou've chosen Hide armor. (-50g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYour health is now   : %4d", hp);
  printf("\nYour agility is now  : %4d", skill);
  resume();
}
int clothArmor()
{
  gold = (gold - 50);
  hp   = (hp + 5);
  skill= (skill + 8);
  printf("\nYou've chosen Cloth armor. (-50g)\n");
  printf("\nYour leftover gold is: %4dg", gold);
  printf("\nYour health is now   : %4d", hp);
  printf("\nYour agility is now  : %4d", skill);
  resume();
}
int riddle()
{
  system("cls");
  printf("You decide it's time for an adventure, and those woods look like just");
  printf("\nthe place to go. You walk over the shrub laden cobblestone path to an");
  printf("\nancient looking fence, surrounded by flora in beautiful contrasts of");
  printf("\ngreen. Suddenly, an Ent walks out from a shaded area, and stands bef-");
  printf("\nore you in a protective demeanor.");
  printf("\n\nEnt: Hello traveller. It seems you seek entrance to my forrest. While");
  printf("\n     it may seem peaceful, danger lurks beyond the shadows at every");
  printf("\n     turn. Before I can let you proceed, you must answer a riddle...");
  printf("\n\n\"At night, they come without being fetched....\"");
  printf("\n\"By day, they are lost without being stolen...\"");
  printf("\n\n1) Bats! The answer is bats!");
  printf("\n2) I believe the answer is stars.");
  printf("\n3) Bloody hell, I just want to kill things!");
  printf("\n\nAnswer: ");
  scanf("%d", &rid);        //rid simply stands for riddle.
}
int riddleBad()
{
  system("cls");
  printf("\nEnt: Incorrect, please try again.");
  printf("\n\n\"At night, they come without being fetched....\"");
  printf("\n\"By day, they are lost without being stolen...\"");
  printf("\n\n1) I'm still positive it's bats!");
  printf("\n2) Well, maybe it is stars...?");
  printf("\n3) Di'int you 'ear me last time, Ent?!?!");
  printf("\n\nAnswer: ");
  scanf("%d", &rid);
}
int riddleGood()
{
  system("cls");
  printf("\nEnt : Very well, traveller. I hope your might matches your mind.");
  printf("\n      Safe travels... And do please watch for my spiders...");
  printf("\n\nGame: The Ent has granted you passage through his forest,");
  printf("\n      however, this does not grant you immunity... I do hope you");
  printf("\n      have prepared yourself for... 'The Murkwood Forest'...");
  resume();
}
int forest()
{
  printf("\t       |  |   \\\\|.'    |  |    \\\\|.'   |  |     \\\\|.'  |  |");
  printf("\n\t       | ||   \\` /   _.| ||,!  \\` /   _| ||\\,!  \\` /   | ||");
  printf("\n\t       ||||`. f |_.-'.'||||\\`. f |_.-'.|||| \\`. f |_.-'||||");
  printf("\n\t       | ||\\ \\|! ,-'   | || \\ \\|! ,-'M | ||  \\ \\|! ,-' | ||");
  printf("\n\t       || |W`. ||  N   || |  `. ||   N || |   `. ||    || |");
  printf("\n\t       ||||H `. |  W   ||||  H`. |   W ||||    `. |    ||||");
  printf("\n\t       || |N  |L|  M   ");
  printf("<   Murkwood Forest   >");
  printf(" N|L|    || |");
  printf("\n\t       | ||W  ||]  H   | ||  W ||]   H | ||    W||]    | ||");
  printf("\n\t       ||||M  [ I  W   ||||  M [ I   W ||||    M[ I    ||||");
  printf("\n\t       || |H  I |  M   || |  H I |   M || |    HI |    || |");
  printf("\n\t       | [|N, !l| ,H\\  | [| /N,!l|  ,H\\| [|   /N!l|    | [|");
  printf("\n\t       || |   '-`      || |    '-`     || |     '-`    || |");
  printf("\n\t      / '| \\          / '| \\          / '| \\          / '| \\\n");
  printf("________________________________________________________________________________");
}
int forestQuest()
{
  system("cls");
  forest();
  printf("\n\nGame: You brush past the Ent, through the gate. As you do, the light");
  printf("\n      around you starts to dim and thick, ancient forest begins to");
  printf("\n      surround you. In the distance you hear the cries of strange c-");
  printf("\n      reatures, and you cautiously look around. Underneath you, you");
  printf("\n      notice a pathway, which you begin to take. As you travel across");
  printf("\n      the ne'er trod earth, you come upon a shoddy sign muddled with");
  printf("\n      what looks to be wormholes, painted in a reddish-black ink reading:");
  printf("\n\n      1) The Dark Hollow\n      2) The Silken Fields\n      3) Spiderling's Grove");
  printf("\n\n      Brave adventurer, which path doth thou choose?: ");  
  scanf("%d", &path);
}
int darkHollow()
{
  system("cls");
  forest();
  printf("\n\nGame: You have chosen to venture to the Dark Hollow. You take a left");
  printf("\n      and peer down the path ahead of you. The lack of sunlight forces");
  printf("\n      your human eyes to refocus, and adjust. In front of you, you be-");
  printf("\n      gin to make out the mangled bodies of dark briar trees, foretel-");
  printf("\n      ling what may become of your fate. No matter, you are brave. You");
  printf("\n      continue on until you reach a gargantuan structure. Bark and ma-");
  printf("\n      ssive fingers splayed in a gruesome symphony of gloom rise above");
  printf("\n      you, taunting your existence. A once giant of the forest lay ho-");
  printf("\n      llow before you. At the base of the massive tree, you see a dark");
  printf("\n      opening, seemingly just big enough to squeeze into and look.....");
  printf("\n\n      What will you do?\n");
  printf("\n      1) Run back to town. My life isn't worth this!");
  printf("\n      2) I am a bold adventurer! I can brave anything.");
  printf("\n\n      Answer: ");
  scanf("%d", &quest);
}
int firstFight()
{
  system("cls");
  forest();
  printf("\n\nGame:You run into the dark hallow with your newfound gallantry. As");
  printf("\n     you do, a spiderling jumps out and attacks you! Brave hero, what");
  printf("\n     shall you do?!\n");
  printf("\n     1) Run back to town. My life isn't worth this!");
  printf("\n     2) Kill the bugger! It's my life or his!");
  printf("\n\n     Answer: ");
  scanf("%d", &quest);
}
int rangerFight()
{
  printf("\n     You run towards the spider and attack with your bow!");
  hit = (rand()%20) + acc;
  printf("\n     Your roll for hit chance with accuracy is: %d", hit);
  printf("\n     The spider's armor provides 15 points of protection.");
  if(hit >= 15) //Hit spider
  {
    dmgGiven = 0;
    dmgGiven = (rand()%attk);
    printf("\n     You do %d damage to the spider!", dmgGiven);
    spider = ((spider) - dmgGiven);
    if(spider > 0)
    {
      printf("\n     Your arrow lodges deep into the spider!");
      printf("\n     The spider's health is now: %d/10", spider);
      spiderDmg = rand()%4;
      hp = hp - spiderDmg;
      printf("\n\n     The spider deals %d damage to you!", spiderDmg);
      printf("\n     Your health is now: %d/%d", hp, maxhp);
      printf("\n\n     Continue? (Y/N): ");
      scanf("%s", &cont);
    }
    else if(spider <= 0) //Spider dies
    {
      printf("\n\n     You've killed the spider!");
      cont = 'n';
      getch();
    }
  }
  else if(hit < 15) //Miss spider
  {
    printf("\n     Your arrow misses the spider alltogether!");
    spiderDmg = rand()%4;
    hp = hp - spiderDmg;
    printf("\n\n     The spider deals %d damage to you!", spiderDmg);
    printf("\n     Your health is now: %d/%d", hp, maxhp);
    printf("\n\n     Continue? (Y/N): ");
    scanf("%s", &cont);
  }
}
int mageFight()
{
  printf("\n     You run towards the spider and attack with your staff!");
  hit = (rand()%20) + acc;
  printf("\n     Your roll for hit chance with accuracy is: %d", hit);
  printf("\n     The spider's armor provides 15 points of protection.");
  if(hit >= 15) //Hit Spider
  {
    dmgGiven = 0;
    dmgGiven = (rand()%attk);
    printf("\n     You do %d damage to the spider!", dmgGiven);
    spider = ((spider) - dmgGiven);
    if(spider > 0)
    {
      printf("\n     Your spell crackles through the spider!");
      printf("\n     The spider's health is now: %d/10", spider);
      spiderDmg = rand()%4;
      hp = hp - spiderDmg;
      printf("\n\n     The spider deals %d damage to you!", spiderDmg);
      printf("\n     Your health is now: %d/%d", hp, maxhp);
      printf("\n\n     Continue? (Y/N): ");
      scanf("%s", &cont);
    }
    else if(spider <= 0) //Spider dies
    {
      printf("\n\n     You've killed the spider!");
      cont = 'n';
      getch();
    }
  }
  else if(hit < 15) //Miss Spider
  {
    printf("\n     Your spell misses the spider alltogether!");
    spiderDmg = rand()%4;
    hp = hp - spiderDmg;
    printf("\n\n     The spider deals %d damage to you!", spiderDmg);
    printf("\n     Your health is now: %d/%d", hp, maxhp);
    printf("\n\n     Continue? (Y/N): ");
    scanf("%s", &cont);
  }
}
int warriorFight()
{
  printf("\n     You run towards the spider and attack with your axe!");
  hit = (rand()%20) + acc;
  printf("\n     Your roll for hit chance with accuracy is: %d", hit);
  printf("\n     The spider's armor provides 15 points of protection.");
  if(hit >= 15) //Hit Spider
  {
    dmgGiven = 0;
    dmgGiven = (rand()%attk);
    printf("\n     You do %d damage to the spider!", dmgGiven);
    spider = ((spider) - dmgGiven);
    if(spider > 0)
    {
      printf("\n     Your axe sinks into the spider!");
      printf("\n     The spider's health is now: %d/10", spider);
      spiderDmg = rand()%4;
      hp = hp - spiderDmg;
      printf("\n\n     The spider deals %d damage to you!", spiderDmg);
      printf("\n     Your health is now: %d/%d", hp, maxhp);
      printf("\n\n     Continue? (Y/N): ");
      scanf("%s", &cont);
    }
    else if(spider <= 0) //Spider dies
    {
      printf("\n\n     You've killed the spider!");
      cont = 'n';
      getch();
    }
  }
  else if(hit < 15) //Miss spider
  {
    printf("\n     Your axe misses the spider alltogether!");
    spiderDmg = rand()%4;
    hp = hp - spiderDmg;
    printf("\n\n     The spider deals %d damage to you!", spiderDmg);
    printf("\n     Your health is now: %d/%d", hp, maxhp);
    printf("\n\n     Continue? (Y/N): ");
    scanf("%s", &cont);
  }
}
int secondCorridor()
{
  system("cls");
  forest();
  printf("\n\n     Game: Well done hero, now onto the next corridor! If you wish");
  printf("\n             to advance, do be careful! Your health in this tunnel is fin-");
  printf("\n             ite! You must be strong enough to reach the end... Lest you");
  printf("\n             expire... What shall you choose? Are you in for the challenge,");
  printf("\n             the glory, and gold? Or are you feared by the inevitable?");
  printf("\n\n             Last chance, what do you choose?");
  printf("\n\n             1) Run back to town, my life really isn't worth THIS!");
  printf("\n             2) I told you already, I am the BRAVEST of adventurers!");
  printf("\n\n             Answer: ");
  scanf("%i", &quest);
}
int secondFight()
{
  system("cls");
  forest();
  printf("\n\n     Game: Very well. The next corridor is long, and at a decline.");
  printf("\n           You decide that it would be wise to take this route slowly. As");
  printf("\n           You look around, you begin to make out web covering the walls.");
  printf("\n           Surely, it was just the spider that lay slain on the ground that");
  printf("\n           spun such a tangled web. He was quite large, and it seems belie-");
  printf("\n           veable. Suddenly, you feel your weight plummit! Your foot is ca-");
  printf("\n           ught on a tripwire of sorts. Blast! The spider got one last jib.");
  printf("\n           In your mind's eye, you believe you hear the sounds of scurrying");
  printf("\n           legs rushing towards you. A arachnid trio! Before you stands th-");
  printf("\n           ree large spiders, black eyes glistening in the dim light and");
  printf("\n           fangs teeming with hunger. The first of the three lunges at you!");
  printf("\n\n           How will you begin this encounter?");
  printf("\n           1) Drink a potion\n           2) Defend yourself\n           3) Attack!");
  printf("\n\n           Answer: ");
  scanf("%i", &quest);
}
int potionDrink()
{
  printf("\n\n     These are your available potions: ");
  printf("\n\n     1) Health = %i/4", health);
  printf("\n     2) Attack = %i/4", attack);
  printf("\n     3) Skill  = %i/4", skill);
  printf("\n\n     Which will you use? : ");
  scanf("%i", &type);
  switch(type)
  {
    case 1: //Health Potion Drink
    {
      if(health > 0)
      {
        printf("\n\n     You drink a health potion!");
        hp = hp + 10;        //Skill modifier
        health = health - 1; //Potion count
        printf("\n     Your health is now %i/%i!", hp, maxhp);
        printf("\n\n     Press any key to continue!");
        getch();
        break;
      }
      if(health <= 0)
      {
        printf("\n\n     You cannot do that! You have no potions of that type!");
        printf("\n\n     Press any key to continue!");
        getch();
        break;
      }
    }
    case 2:  //Attack Potion Drink
    {
      if(attack > 0)
      {
        printf("\n\n     You drink an attack potion!");
        attk = attk + 5;     //Skill modifier
        attack = attack - 1; //Potion count
        printf("\n     Your attack is now %i!", attk);
        printf("\n\n     Press any key to continue!");
        getch();
        break;
      }
      if(attack <= 0)
      {
        printf("\n\n     You cannot do that! You have no potions of that type!");
        printf("\n\n     Press any key to continue!");
        getch();
        break;
      }
    }
    case 3:  //Skill Potion Drink
    {
      if(skill > 0)
      {
        printf("\n\n     You drink a skill potion!");
        ski = ski + 10;    //Skill modifier
        skill = skill - 1; //Potion count
        printf("\n     Your skill is now %i!", ski);
        printf("\n\n     Press any key to continue!");
        getch();
        break;
      }
      if(skill <= 0)
      {
        printf("\n\n     You cannot do that! You have no potions of that type!");
        printf("\n\n     Press any key to continue!");
        getch();
      }
    }
    default:
    {
      printf("Invalid potion. Press any key to continue");
      getch();
    }
  }
}
