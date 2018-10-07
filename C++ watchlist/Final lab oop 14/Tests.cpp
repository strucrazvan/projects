
//#include "Tests.h"
//#include "Tutorial.h"
//#include <assert.h>
//#include "DynamicVector.h"
//#include "Repository.h"
//#include "Controller.h"
//#include "WatchList.h"
//#include "Comparator.h"
//#include <stdio.h>
//
//void Tests::testTutorial()
//{
//	Duration d{ 4, 54 };
//	Tutorial t {  "C++ the best","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	assert(t.getTitle() == "C++ the best");
//	assert(t.getPresenter() == "Gabi Mircea Aurel");
//	assert(t.getLink() == "https://www.facebook.com/gabi.mircea.9");
//	assert(t.getLikes() == 1);
//	assert(t.getDuration().getMinutes() == 4);
//	assert(t.getDuration().getSeconds() == 54);
//	assert(t.accessLink() == true);
//	Tutorial t2{ "C++ the best1","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	assert(t == t2 == false);
//}
//void Tests::testWatchList()
//{
//	DynamicVector<Tutorial> v;
//	Duration d{ 4, 54 };
//	WatchList w;
//	assert(w.getCurrentTutorial() == Tutorial{});
//	Tutorial t{ "C++ the best","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	
//	w.add(t);
//	assert(w.getCurrentTutorial() == t);
//	Tutorial t2{ "C++ the best2","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.92" };
//	w.add(t2);
//	w.next();
//	assert(w.getCurrentTutorial() == t2);
//	w.play();
//	assert(w.getCurrentTutorial() == t);
//	assert(w.getTutorials().getSize() == 2);
//
//}
//
//void Tests::testDynamicVector()
//{
//	DynamicVector<Tutorial> v;
//	Duration d{ 4, 54 };
//	Tutorial m{ "C++ the best","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	
//
//	assert(v.getSize() == 0);
//
//	v.add(m);
//	assert(v.getSize() == 1);
//	DynamicVector<Tutorial> v2(v);
//	assert(v2.getSize() == 1);
//
//	DynamicVector<Tutorial> v3;
//	v3 = v;
//	assert(v.getSize() == 1);
//
//	Tutorial m1{ "C++ the best","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	v.update(0, m1);
//	v.update(-1, m1);
//	assert(v.getAllElems()[0].getTitle() == "C++ the best");
//
//	v.remove(0);
//	v.remove(-2);
//	assert(v.getSize() == 0);
//	v - m;
//	assert(v.getSize() == 0);
//
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//	v.add(m);
//}
//
//void Tests::testRepository()
//{
//	Repository repo{};
//	assert(repo.findTutorialByTitle("C++ the best") == Tutorial{});
//	Duration d{ 4, 54 };
//	Tutorial t{ "C++ the best","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	repo.addTutorial(t);
//	assert(repo.findTutorialByTitle("C++ the best").getTitle() == "C++ the best");
//	assert(repo.findTutorialByTitle("asd").getTitle() == "");
//
//	Tutorial t1{ "C++ the best1","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	repo.updateTutorial(t, t1);
//	assert(repo.findTutorialByTitle("C++ the best1").getTitle() == "C++ the best1");
//	repo.updateTutorial(t, t1);
//
//	repo.removeTutorial(t);
//	assert(repo.findTutorialByTitle("C++ the best").getTitle() == "");
//	assert(repo.getTutorials().getSize()==1);
//
//}
//void Tests::testComparator()
//{
//	Duration d{ 4, 54 };
//	ComparatorAscendingByTitle comp;
//	Repository repo{};
//	Controller c{ repo };
//	Tutorial t{ "C++ the best2","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	Tutorial t2{ "C++ the best1","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	DynamicVector<Tutorial> vect;
//
//	repo.addTutorial(t);
//	repo.addTutorial(t2);
//	vect = sortFunction(repo.getTutorials(), comp);
//	assert(vect.getSize() == 2);
//	assert(vect.getAllElems()[1].getTitle() == "C++ the best2");
//}
//void Tests::testController()
//{
//	Repository repo{};
//	Controller c{repo};
//	assert(c.add("C++ the best", "Gabi Mircea Aurel", 4,5, 1, "https://www.facebook.com/gabi.mircea.9") == true);
//	assert(c.add("C++ the best", "Gabi Mircea Aurel", 4, 5, 1, "https://www.facebook.com/gabi.mircea.9") == false);
//	assert(c.getRepo().findTutorialByTitle("C++ the best").getTitle() == "C++ the best");
//	assert(c.update("C++ the best","C++ the best1", "Gabi Mircea Aurel", 4, 5, 1, "https://www.facebook.com/gabi.mircea.9") == true);
//	assert(c.getRepo().findTutorialByTitle("C++ the best1").getLikes() == 1);
//	assert(c.update("C++ the best1", "C++ the best", "Gabi Mircea Aurel", 4, 5, 1, "https://www.facebook.com/gabi.mircea.9") == true);
//	assert(c.update("C++ the best13412", "C++ the best", "Gabi Mircea Aurel", 4, 5, 1, "https://www.facebook.com/gabi.mircea.9") == false);
//
//	assert(c.remove("C++ the best") == true);
//	assert(c.remove("C++ the best") == false);
//
//	assert(c.getRepo().findTutorialByTitle("C++ the best").getTitle() == "");
//
//
//	Duration d{ 4, 54 };
//	Tutorial t{ "C++ the best4","Gabi Mircea Aurel",d,1,"https://www.facebook.com/gabi.mircea.9" };
//	c.addTutorialToWatchList(t);
//	c.nextTutorialWatchList();
//	assert(c.getWatchList().getCurrentTutorial().getTitle() == "C++ the best4");
//	c.startWatchList();
//	assert(c.getWatchList().getCurrentTutorial().getTitle() == "C++ the best4");
//
//	assert(c.getWatchList().getCurrentTutorial() == t);
//	c.add("C++ the best4", "Gabi Mircea Aurel", 4, 5, 1, "https://www.facebook.com/gabi.mircea.9");
//	c.removeTutorialFromWatchList(true);
//	assert(c.getRepo().findTutorialByTitle("C++ the best4").getLikes() == t.getLikes()+1);
//
//}