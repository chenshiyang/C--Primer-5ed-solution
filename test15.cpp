#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<algorithm>

#include "test15_Quote.h"
#include "test15_13_base.h"
#include "test15_15_DiscQuote.h"
#include "test15_18_Base.h"
#include "test15_30_Basket.h"

using namespace std;

int main() {
    //test 15.3 15.5 15.6
//    Quote book1("book1", 30.0);
//    print_total(cout, book1, 3);
//    Bulk_quote book2("book2", 30.0, 2, 0.2);
//    print_total(cout, book2, 4);
//    //test 15.7
//    Limit_quote book3("book3", 30.0, 5, 0.2);
//    print_total(cout, book3, 6);
//
//    //test 15.11
//    book1.debug();
//    book2.debug();
//    book3.debug();
//
//    Bulk_quote bq;
//    Quote q(bq);
//    q = bq;


    //test 15.13
//    base b("b");
//    derived d("d", 1);
//    b.print(cout);
//    d.print(cout);

    //test 15.14
//    base bobj("bobj");
//    base *bp1 = &bobj;
//    base &br1 = bobj;
//    derived dobj("dobj", 1);
//    base *bp2 = &dobj;
//    base &br2 = dobj;
//    //(a)
//    bobj.print(cout);
//    //(b)
//    dobj.print(cout);
//    //(c)
//    bp1->name();
//    //(d)
//    bp2->name();
//    //(e)
//    br1.print(cout);
//    //(f)
//    br2.print(cout);


    //test 15.15, 15.16, 15.17
//    Quote book1("book1", 30.0);
//    print_total(cout, book1, 3);
//    BulkQuote book2("book2", 30.0, 2, 0.2);
//    print_total(cout, book2, 4);
//    //test 15.7
//    LimitQuote book3("book3", 30.0, 5, 0.2);
//    print_total(cout, book3, 6);
////    DiscQuote book4("book4", 30.0, 4, 0.2);

    //test 15.18, 15.19, 15.20
//    Pub_Derv d1;
//    Priv_Derv d2;
//    Prot_Derv d3;
//    Derived_from_Public dd1;
//    Derived_from_Protected dd2;
//    Derived_from_private dd3;
//
//    Base* p = &d1;//ok
////    p = &d2;//wrong
////    p = &d3;//wrong
//
////    p = &dd1;//ok
////    p = &dd2;//wrong
////    p = &dd3;//wrong

    //test 15.26
////    DiscQuote dq;// can not declare.
//    Quote q("quote", 0.2);
//    BulkQuote bq("bulk_quote", 30, 2, 0.2);
//    LimitQuote lq("limit_quote", 30, 2, 0.2);
//    LimitQuote lq2(lq);
//    q = lq;
//    Quote q2(bq);
//    lq2 = lq;


    //test 15.28
//    BulkQuote bq1("book1", 30, 5, 0.2);
//    vector<Quote> basket;
//    basket.push_back(bq1);
//    basket.push_back(bq1);
//    double sum = 0.0;
//    for_each(basket.cbegin(), basket.cend(), [&sum] (const Quote& q) { sum += q.net_price(6);});
//    cout << sum << endl;// 30 * 6 + 30 * 6 = 360

    //teset 15.29
//    vector<shared_ptr<Quote>> basket;
//    basket.push_back(make_shared<Quote>("quote1", 30));
//    basket.push_back(make_shared<BulkQuote>("bulk_quote1", 30, 5, 0.2));
//    double sum = 0.0;
//    for_each(basket.cbegin(), basket.cend(), [&sum] (shared_ptr<Quote> q) { sum += q -> net_price(6); });
//    cout << sum << endl;// 30 * 6 + 30 * 6 * 0.8 = 324


    //test 15.30
//    Basket bsk;
//    BulkQuote bq("bq", 30.0, 2, 0.2);
//    Quote q("q", 30.0);
//    bsk.add_item(bq);
//    bsk.add_item(q);
//    bsk.add_item(bq);
//    bsk.add_item(bq);
//    bsk.add_item(q);
//    bsk.total_receipt(cout);

    return 0;
}
