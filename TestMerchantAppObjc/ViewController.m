//
//  ViewController.m
//  TestMerchantAppObjc
//
//  Created by Jorge Zapata on 23/03/18.
//  Copyright © 2018 Jorge Zapata. All rights reserved.
//

#import "ViewController.h"
#include <MCCMerchant/MCCAmount.h>
#include <MCCMerchant/MCCBlocks.h>
#include <MCCMerchant/MCCCardType.h>
#include <MCCMerchant/MCCCheckoutRequest.h>
#include <MCCMerchant/MCCCheckoutResponse.h>
#include <MCCMerchant/MCCConfiguration.h>
#include <MCCMerchant/MCCCryptogram.h>
#include <MCCMerchant/MCCErrors.h>
#include <MCCMerchant/MCCMasterpassButton.h>
#include <MCCMerchant/MCCMerchant.h>
#include <MCCMerchant/MCCMerchantConstants.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIView *viewMasterpass;
@property  MCCMasterpassButton * _Nullable masterPassButton;
@end

@implementation ViewController

NSString * const TAG = @"ViewController";

- (void)viewDidLoad {
    [super viewDidLoad];

    
    MCCConfiguration * configuration = [[MCCConfiguration alloc] init];
    configuration.enableAnalytics = true;
    configuration.merchantUrlScheme = @"TestMerchantAppObjc://";
    configuration.locale = NSLocale.currentLocale;
    
    [MCCMerchant initializeSDKWithConfiguration:(configuration) onStatusBlock:^(NSDictionary * _Nonnull status, NSError * _Nullable error) {
        
        
        NSInteger statusCode = (int) [status valueForKey:kInitializeStateKey];
        NSLog(@"%li - statusCode", statusCode);
        
         switch (statusCode) {
            case 18: //Started code
                NSLog(@"%@ - started", TAG);
                break;
            
            case 34: //Completed code
                NSLog(@"%@ - completed", TAG);
                self.masterPassButton = [self getMasterPassButton];
                 if (self.masterPassButton != nil){
                     [self.masterPassButton addButtonToview:(self.viewMasterpass)];
                 }
                break;
                
            default:
                NSLog(@"%@ - fail", TAG);
                 if (self.masterPassButton != nil) {
                     [self.masterPassButton removeFromSuperview];
                 }
                break;
        }
    }];
    
    
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (MCCMasterpassButton * _Nullable)getMasterPassButton{
    MCCMasterpassButton * masterpassButton = [MCCMerchant getMasterPassButton:(self)];
    return masterpassButton;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)didGetCheckoutRequest:(nullable BOOL (^)(MCCCheckoutRequest * _Nonnull))completionBlock {
    
    // Init the chechoutRequest
    MCCCheckoutRequest * transactionRequest = [[MCCCheckoutRequest alloc] init];
    
    //check merchant on-boarding process for checkoutId & cartID
    transactionRequest.checkoutId = @"{ADD_YOUR_CHECKOUTID}";
    transactionRequest.cartId = @"{ADD_YOUR_CARTID}";
    
    //amount and currency
    NSDecimalNumber * amt = [[NSDecimalNumber alloc] initWithString:(@"75")];
    MCCAmount * amount = [[MCCAmount alloc] init];
    amount.total = amt;
    amount.currencyCode = @"USD";
    transactionRequest.amount = amount;
    
    //network type
    
    //Type of card
    MCCCardType * mccCard = [[MCCCardType alloc] initWithType:MCCCardMASTER];
    
    NSSet*  allowedNetworkTypesSet = [[NSSet alloc] initWithObjects:(mccCard), nil];
    transactionRequest.allowedCardTypes = allowedNetworkTypesSet;
    
    //cryptogram type
    
    MCCCryptogram * mccCryptogram = [[MCCCryptogram alloc] initWithType:(MCCCryptogramUCAF)];
    transactionRequest.cryptogramType = mccCryptogram;
    
    //shipping required
    transactionRequest.isShippingRequired = true;
    
    completionBlock(transactionRequest);
}

- (void)didReceiveCheckoutError:(NSError * _Nonnull)error {
    NSError *  errorObject = (NSError*) error;
    if (errorObject.domain == MCCMerchantSDKTransactionErrorDomain) {
        //Do something with error
        
        NSLog(@"%@ Error - %@", TAG, error.localizedDescription);
        //self.showErrorDialogue(error.localizedDescription, action: nil)
    } else {
        NSLog(@"%@ ErrorObject - %@", TAG, errorObject.description);
        //self.showError(errorObject)
    }
}


- (void)didFinishCheckout:(MCCCheckoutResponse * _Nonnull)checkoutResponse {
    MCCResponseType webCheckoutType = checkoutResponse.responseType;
    if (webCheckoutType == MCCResponseTypeWebCheckout){
        //do something
        NSLog(@"%@ TransactionId - %@" , TAG, checkoutResponse.transactionId);
    }
}



@end
