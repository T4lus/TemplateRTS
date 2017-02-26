// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Data.h"
#include "PlayerPawn.generated.h"

class AAIBase;
class ABuilding;

UCLASS()
class TEMPLATERTS_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "TemplateRTS")
	int GetGoldPossessed();

	UFUNCTION(BlueprintCallable, Category = "TemplateRTS")
	EAgesEnum GetCurrentAge();

	void EarnGold(int Amount);

	int GetTeamNumber();

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TemplateRTS")
	USceneComponent* _sceneComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TemplateRTS")
	USpringArmComponent* _springArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TemplateRTS")
	UCameraComponent* _mainCamera;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TemplateRTS")
	float actionLength;

	UFUNCTION(BlueprintImplementableEvent, Category = "TemplateRTS")
	void SetHUDByUnitType(EUnitTypeEnum type);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TemplateRTS")
	EPlayerStateEnum _playerState;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TemplateRTS")
	ABuilding* _placingBuilding;

private:

	void ActionOne();
	void FinishActionOne();

	void ActionTwo();
	
	void ClearSelectedUnit();

	void MakeSquareSelection(const FVector& currentPos);

private:

	FVector _lastMousePos;
	bool _executingActionOne;

	APlayerController* _playerController;

	TArray<AAIBase*> _selection;
	UBoxComponent* _currentSelectionBox;

	int _goldPossessed;

	EAgesEnum _currentAge;

	int _teamNumber;

};
